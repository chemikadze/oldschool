<?php
	include($_SERVER["DOCUMENT_ROOT"] . "/php/title.inc");
?>
<form method="GET" action="<?php echo $_SERVER["PHP_SELF"]; ?>">
	<h3>Enter email to check it</h3>
	<input type="text" name="email" value="<?php if (isset($_GET["email"])) echo $_GET["email"]; ?>" />
	<input type="submit" name="submit" value="Check" />
</form>
<?php
	$reg='^[A-Za-z.]+@[a-z.-]+$';
	echo $reg;
	if ( isset($_GET["email"]) )
		if (ereg($reg , $_GET["email"]) )
			echo "<h4><font color=\"#00FF00\">Correct</font></h4>";
		else
			echo "<h4><font color=\"#FF0000\">Incorrect</font></h4>";
	include($_SERVER["DOCUMENT_ROOT"] . "/php/footer.inc");
?>
