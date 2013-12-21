<?php
	include("./title.inc");

	echo "<table><tr><td>Переменная</td><td>Значение</td></tr>";
	foreach( $_GET as $key => $value )
	{
		echo "<tr><td>$key</td><td>$value</td></tr>";
	}
	echo "</table>";

	include("./footer.inc");
?>
