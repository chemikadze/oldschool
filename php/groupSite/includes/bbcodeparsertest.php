<?php
	require_once('bbcodeparser.php');
	$file = fopen('prim.bb', 'r');
	$data = '';
	while ( $buf = fread($file, 1024))
		$data .= $buf;
		
	echo parse_bbcode($data);
?>
