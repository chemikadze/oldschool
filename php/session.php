<?php
	include($_SERVER['DOCUMENT_ROOT'] . "/php/title.inc");

	session_start();
	$_SESSION['lol'] = 'troll';
	echo 'in cookie: ' . session_id() . ' lol:' .  $_SESSION['lol'] . '<br/>';
	session_regenerate_id(true);
	echo 'new: ' . session_id() . ' lol:' .  $_SESSION['lol'];
	echo '<br/>' . session_name();
	
	include($_SERVER['DOCUMENT_ROOT'] . "/php/footer.inc");
?>
