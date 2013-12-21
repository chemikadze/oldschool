<?php
	$alpha = 0.01;
	$n = 1;
	$S = 0;
	while ( ($val = 1/(pow($n, 3)+1)) >= $alpha )
	{
		printf("S(%d) = %f\t\t1 / (%f + 1)\n", $n, $val, pow($n, 3));
		$n++;
		$S += $val;
	}
	printf("S(%d) = %f\t\t1 / (%f + 1)\n", $n, $val, pow($n, 3));
	echo $S;
?>					
