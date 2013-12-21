
<?php
	require_once 'constants.php';

	function validate_username($username)
	{
		return ereg('[0-9a-zA-Z_-]+', $username) && strlen($username) <= 128;
	}

	function passhash($pass)
	{
		return md5('salt'. $pass . 'some pepper' );
	}

	function redirect($where)
	{
		header("Location: $where");
		exit();
	}

	function user_exists($username)
	{
		$username = mysql_real_escape_string($username);
		$query = "SELECT count(*) FROM users WHERE username = '$username';";
		$result = mysql_query($query);
		return (bool)mysql_result($result, 0, 0);
	}

	function subject_exists($id)
	{
		$id = mysql_escape_string($id);
		$result = mysql_query( "SELECT count(*) FROM subjects WHERE subjects.ID = '$id';" ) or throwException($errors['DB'] . mysql_error());
		return (bool)mysql_result($result, 0, 0);
	}

	function throwException($err)
	{
		throw new Exception($err);
	}

	function mysql_query_e($query)
	{
		global $errors;
		if (! $result = mysql_query($query)) 
			throwException($errors['QUERY'] . $query);
		return $result;
	}
	
	function mysql_set_time_region($region)
	{
		$region = mysql_real_escape_string($region);
		mysql_query_e( "SET lc_time_names = '$region';");
	}
?>
