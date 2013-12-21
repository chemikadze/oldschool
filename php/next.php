<?php
	include "title.inc";

	$num=$_GET['num'];
	if ($num == NULL)
		$num = 1;
	
	$next=$num+1; $prev=$num-1;
	print("You are at <b>$num</b> page.<br/>");
	
	if ($prev > 0 )
		print("<a href=\"next.php?num=$prev\">Back</a>&nbsp;");
	else
		print("Back&nbsp;");

	if ($next < 10)
		print("<a href=\"next.php?num=$next\">Forward</a>");
	else
		print("Forward");

	include "footer.inc";
?>
