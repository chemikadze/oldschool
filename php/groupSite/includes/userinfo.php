<?php
	require_once('common.php');

	function getUserinfo($username)
	{
		global $access_strings;
		global $gender_strings;

		if (!validate_username($username))
			return false;
		$username = mysql_real_escape_string($username);
		$query = "SELECT * FROM users WHERE username = '$username';";
		$result = mysql_query($query)	or throwException($errors['DB'] . mysql_error());
		if (!mysql_num_rows($result))
			return false;
		$user = mysql_fetch_array($result, MYSQL_ASSOC) or throwException($errors['DB'] . mysql_error());
		unset($user['passhash']);
		$user['access_string'] = $access_strings[ $user['access'] ];
		$user['gender_string'] = $gender_strings[ $user['gender'] ];

		return $user;
	}

	function submitUserinfo($username, & $error)
	{
		global $user;
		global $errors;
		global $register_errors;

		$fields = 'online = online'; // dirty
		if ((isset($_POST['oldpassword']) && $_POST['oldpassword']) || ($username != $user->username && $user->access > 1))
		{
			if (isset($_POST['oldpassword']))
			{
				$phash = passhash($_POST['oldpassword']);
				$query = "SELECT count(*) FROM users WHERE username = '$username' AND passhash = '$phash';";
				// $query = "SELECT passhash = '$phash' FROM users WHERE username = '$username';";
				$result = mysql_query($query) or throwException($errors['DB']);
				if (!mysql_result($result, 0, 0))
				{
					$error = $errors['PASSW'];
					return false;
				}
			}
			if	(!(isset($_POST['newpassword']) && isset($_POST['repeatpassword']) && 
				   $_POST['newpassword']==$_POST['repeatpassword'] && 
				   strlen($_POST['newpassword']) >=5))
			{
				$error = $register_errors['PASSW'];
				return false;	
			}
			$passhash = passhash($_POST['newpassword']);
			if ($fields) $fields .= ', ';
			$fields .= "passhash = '$passhash'";
		}
		if	(!(isset($_POST['email']) && filter_var($_POST['email'], FILTER_VALIDATE_EMAIL)))
		{
			$error = $register_errors['EMAIL'];
			return false;
		}
		foreach (array('email', 'name', 'secondname', 'fathername', 'gender', 'phone', 'homepage', 'icq', 'jabber') as $key)
		{
			$val = mysql_real_escape_string(htmlspecialchars($_POST[$key]));
			$fields .= ", $key = '$val'";
		}
		$query = "UPDATE users SET $fields WHERE username = '$username';";
		mysql_query_e($query);
		return true;
	}
?>
