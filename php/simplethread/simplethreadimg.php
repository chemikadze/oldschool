<?php
	header("Content-type: image/gif");
	if (isset($_GET['id']))
	{
		mysql_connect('localhost', 'chemikadze', 'batkabatka');
		mysql_select_db('simplethread');
		$res = mysql_query("SELECT file FROM messages WHERE ID = {$_GET['id']};");
		if (mysql_num_rows($res) != 0)
		{
			$data = mysql_fetch_array($res);
			$img = $data['file'];
			echo $img;
			exit;
		}
	}
	header("HTTP/1.0 404 Not Found");
?>

