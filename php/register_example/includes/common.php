<?php

	function mysql_die()
	{
		echo ('MySQL function died with error: "<b>'. mysql_error() .'"</b>');
		return 0;
	}
	
	function database_connect()
	{
		if (! (mysql_connect("localhost", "chemikadze", "batkabatka") &&
			mysql_select_db("register_example")) )
		{
			mysql_die();
			return false;
		}
		return true;
	}

	function get_password($username)
	{
		$query = "SELECT password FROM users WHERE username='$username\';";
		$res = mysql_query( $query );
		if ( ! $res )
		{
			mysql_die();
			return "";
		}
		return mysql_result($res, 0, 0);
	}

	function cook_password($password)
	{
		return md5(md5($password)+'salt&pepper');
	}

// ящитаю, проверку пароля каждый раз надо убрать
	function check_login()
	{
		if (! (isset($_GET['action']) && $_GET['action']=='logout') )
		{

			if (isset($_SESSION['username']))
				return 1;
			if (isset($_POST['login_btn']))
			{
				$username = $_POST['login'];
				$password = $_POST['passw'];
				$truepass = get_password( $username );
				if ( $truepass != "" && $truepass == cook_password($password) )
				{
					$_SESSION['username'] = $username;
					$_SESSION['password'] = $truepass;
					return 1;
				}
			}
		}
		unset($_SESSION['username']);
		unset($_SESSION['password']);
		return 0;
	}

	function get_user_info($username)
	{
		$query = "SELECT username, name, email, surname, comment FROM users WHERE username = '$username';";
		$result = mysql_query($query);
		if (! $result)
		{
			mysql_die();
			return 0;
		}
		if (mysql_num_rows($result) == 1)
			return mysql_fetch_array($result);
		else
			return 0;
	}

	function process_register_data()
	{
		$username = $_POST['username'];
		$_POST['username'] = htmlspecialchars($_POST['username']);
		if (get_user_info($_POST['username']) != 0)
			return 0;
		// check email
		$_POST['username'] = mysql_escape_string($_POST['username']);
		$_POST['password'] = cook_password($_POST['password']);
		$_POST['email'] = mysql_escape_string(htmlspecialchars($_POST['email']));
		$_POST['name'] = mysql_escape_string(htmlspecialchars($_POST['name']));
		$_POST['surname'] = mysql_escape_string(htmlspecialchars($_POST['surname']));
		$_POST['comment'] = mysql_escape_string($_POST['comment']);
		$query = "INSERT INTO users(username, password, email, name, surname, comment) VALUE ('{$_POST['username']}', '{$_POST['password']}', '{$_POST['email']}', '{$_POST['name']}', '{$_POST['surname']}', '{$_POST['comment']}');";
		if (!mysql_query($query))
		{
			mysql_die();
			return 0;
		}
		$_SESSION['username'] = $username;
		return 1;	
	}
?>
