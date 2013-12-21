<?php
	include("title.inc");

	echo "<h3>Division table</h3>";
	echo "<table border=1>";

	echo "<tr><th></th>";
	for ($i=2; $i<10; $i++)
		echo "<th>$i</th>";
	echo "</tr>";

	for ($i=2; $i < 10; $i++)
	{
		echo "<tr><th>$i</th>";
		for ($j=2; $j < 10; $j++)
		{
			$res = $i * $j;
			echo "<td>$res</td>";
		}
		echo "</tr>";
	}

	echo "</table>";
	include("footer.inc");
?>
