<?php
	require_once('common.php');

	function regenerate_sessid()
	{
		return md5(microtime());
	}

	class User
	{
		var $userid=0;
		var $username;
		var $access=0;
		var $datarow; // mysql_fetch_array() result
		var $login_error_str; // TODO: make some errors
		
		function __construct()
		{
		}

		function __destruct()
		{
		}

	//  read post data / cookies
		function login()
		{
			global $errors;
			if (isset($_POST['login']) && isset($_POST['password']) && 
				validate_username($_POST['login']))
			{
				$login = $_POST['login'];
				$password = $_POST['password'];
				$hash = passhash($password);

				$query = "SELECT * FROM users WHERE username='$login' AND passhash='$hash';";
				$result = mysql_query($query) or throwException($errors['QUERY'] . mysql_error());
				if (mysql_num_rows($result))
				{
					$user_array = mysql_fetch_array($result, MYSQL_ASSOC);
					
					$userid = $user_array['ID'];
					$msessid = mysql_real_escape_string($sessid = regenerate_sessid());
					
					$this->userid = $userid;
					$this->username = $user_array['username'];
					$this->access = $user_array['access'];
					$this->datarow = $user_array;
					$this->sessid = $sessid;

					$query = "DELETE FROM sessions WHERE userid = $userid;";
					mysql_query($query) or throwException($errors['QUERY'] . mysql_error());
					$query = "INSERT INTO sessions(userid, sessid) VALUES ($userid, '$msessid');";
					mysql_query($query) or throwException($errors['QUERY'] . mysql_error());

					$_SESSION['user'] = $this->datarow;

					return true;
				}
				else
					 $this->login_error_str=$errors['USERPASSW'];
			}
			return false;
		}

	//  end session and clear cookies
		function logout()
		{
			global $errors;
			if (isset($_COOKIE['sessid']) && isset($_COOKIE['userid']))
			{
			//	$sessid = mysql_real_escape_string($_COOKIE['sessid']);
				$userid = mysql_real_escape_string($_COOKIE['userid']);
				$query = "DELETE FROM sessions WHERE userid=$userid;";
				mysql_query($query) or throwException($errors['QUERY'] . mysql_error());
			}
			session_destroy() or throwException($errors['SESS']);
			setcookie('sessid', NULL);
			setcookie('userid', NULL);
		}

	// check session and login
		function checkSession()
		{
			global $errors;

			if (isset($_SESSION['user']))
			{
				$suser = $_SESSION['user'];
				$this->userid = $suser['ID'];
				$this->username = $suser['username'];
				$this->access = $suser['access'];
				$this->datarow = $suser;
				$userid = $this->userid;
			}
			else
			{
				if (!(isset($_COOKIE['sessid']) && $sessid = mysql_real_escape_string($_COOKIE['sessid'])))
					return false;
				$query = "SELECT users.* FROM sessions INNER JOIN users ON sessions.userid=users.ID WHERE sessions.sessid = '$sessid';";
				$result = mysql_query($query) or throwException($errors['QUERY'] . mysql_error());
				if ( mysql_num_rows($result) == 0 )
					return false;
				$user_array = mysql_fetch_array($result, MYSQL_ASSOC);
				$userid = $user_array['ID'];
				if ( (!isset($_COOKIE['userid'])) || $_COOKIE['userid'] != $userid )
					return false;
				$this->userid = $userid;
				$this->username = $user_array['username'];
				$this->access = $user_array['access'];
				$this->datarow = $user_array;
			}

			$msessid=mysql_real_escape_string($sessid=regenerate_sessid());
			$query = "UPDATE sessions SET sessid='$msessid' WHERE userid=$userid;";
			mysql_query($query) or throwException($errors['QUERY'] . mysql_error());
			$this->sessid = $sessid;

			return true;
		}
	};
?>
