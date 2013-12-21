<?php                     
	$str = 'one Two Three FFFFFFour five six';
	$res = preg_match_all( '/([A-Z]+)(.[^ ]*)/', $str, $res_arr, PREG_SET_ORDER);
	print_r($res_arr);                                                           
?>
