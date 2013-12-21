<?php
	mysql_connect('localhost', 'chemikadze', 'batkabatka');
	mysql_select_db('db');
	$res = mysql_query( 'select * from tab1;' );
	print_r($res);
?>
