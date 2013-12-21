<?php
	require_once('htmlparser.php');
	$file = fopen('prim.html', 'r');
	$data = '';
	while ( $buf = fread($file, 1024))
		$data .= $buf;
		
	echo parse_html($data);
?>
