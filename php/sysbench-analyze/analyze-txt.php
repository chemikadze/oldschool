<?php
	$fd = fopen("data.txt", "r");
	$data = "";
	while ( $buf = fread( $fd, 1024 ) )
		$data .= $buf;

	
	// $regexp = '/Memory block size\\:\s+([0-9]+).+transferred \(([0-9.])[^)]+\)/';
	$regexp = '/Memory block size\\:\s+([0-9]+)[^B]+B transferred \\(([0-9.]+)[^\\)]+\\)/';
	
	preg_match_all( $regexp, $data, $vars, PREG_SET_ORDER);

	foreach ( $vars as $test_result )
	{
		echo "{$test_result[1]} {$test_result[2]}\n";
	}
?>
