<?php
	require_once('common.php');
	
	function register( & $error )
	{
		global $register_errors;
		if (!(isset($_POST['username']) && validate_username($_POST['username'])))
		{ 
			$error = $register_errors['NAME'];
			return false; 
		}
		
		if (user_exists($_POST['username']))
		{
			$error = $register_errors['EXISTS'];
			return false;
		}

		if	(!(isset($_POST['password']) && isset($_POST['repeatpassword']) && 
			   $_POST['password']==$_POST['repeatpassword'] && 
			   strlen($_POST['password']) >=5))
		{
			$error = $register_errors['PASSW'];
			return false;
		}

		if	(!(isset($_POST['email']) && filter_var($_POST['email'], FILTER_VALIDATE_EMAIL)))
		{
			$error = $register_errors['EMAIL'];
			return false;
		}

		$username = mysql_real_escape_string(htmlspecialchars($_POST['username']));

		$fields = "username";
		$values = "'$username'";
		$_POST['passhash'] = passhash($_POST['password']);

		foreach (array('passhash', 'name', 'secondname', 'fathername', 'email', 
					   'phone', 'homepage', 'icq', 'jabber', 'access', 'gender') as $key)
		{
			if (isset($_POST[$key]))
			{
				$fields .= ", $key";
				$val = mysql_real_escape_string(htmlspecialchars($_POST[$key]));
				$values .= ", '$val'";
			}
		}
		
		echo $query = "INSERT INTO users($fields) VALUES ($values);";
		mysql_query($query) or throwException($errors['DB'] . mysql_error());

		return $username;
	}
?>
