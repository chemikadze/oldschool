<?php
	include($_SERVER['DOCUMENT_ROOT'] . "/php/title.inc");
//	include("title.inc");

	echo 	
	'<p><form method="POST" action="' . "{$_SERVER['PHP_SELF']}" . '">
		<table>
		<tr><td>Name:</td><td><input type="text" name="name" /></td></tr>
		<tr><td>Email:</td><td><input type="text" name="email" /></td></tr>
		<tr><td>Message:</td><td><textarea name="message" cols="60" rows="5"></textarea></td></tr>
		<tr><td></td><td><input type="submit" name="submit" value="Send"></td></tr>
	</form></p>';

	if (! mysql_connect('localhost', 'chemikadze', 'batkabatka')) 	die('Can\'t connect to database server...');
	if (! mysql_select_db('guestbook')) 				die('Can\'t connect to database...');
	if (isset($_POST['submit']) && isset($_POST['message']))
	{
		$name=$_POST['name'];
		$email=$_POST['email'];
		$message=addslashes($_POST['message']);
		date_default_timezone_set('Europe/Moscow');
		$time=date('H:i:s');
		$date=date('Y-m-d');
	
		$query = "INSERT INTO guestbook(name, email, time, date, message) VALUES ('$name', '$email', '$time', '$date', '$message');";
		if (!mysql_query($query))	die('Can\'t post this: ' . mysql_error() . "<b>$query</b>");
	}	
	$query = "SELECT name, email, time, date, message FROM guestbook ORDER BY date, time;";
	if (! $data = mysql_query($query)) die('Can\'t get messages!');
	while ($row = mysql_fetch_array($data))
	{
		$name = $row['name'];
		if (!isset($name))
			$name = "<font color='#AAAAAA'>Anonymous</font>";
		$email = $row['email'];
		if (strlen($email) != 0)
			$email = "(<a href=\"mailto:$email\">$email</a>)";
		$time = $row['time'];
		$date = $row['date'];
		$message = stripslashes($row['message']);
		echo 	"<table width=\"90%\">
			<tr bgcolor=\"#99CCFF\"><td width=\"80%\">Отправитель: $name $email</td><td><div align=\"right\"><font color=\"#111111\">$date $time</font></div></td></tr>
			<tr bgcolor=\"#CCFFFF\"><td colspan=\"2\">$message</td></tr>
			</tr></table><br />";
	}

	include($_SERVER['DOCUMENT_ROOT'] . "/php/footer.inc");
	//include("footer.inc");
?>
