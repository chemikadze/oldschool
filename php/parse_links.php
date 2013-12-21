<?php
	include($_SERVER["DOCUMENT_ROOT"] . "/php/title.inc");

	function parse_links($url)
	{
		$fd = fopen($url, "r");
		if ($fd == NULL || !isset($fd))
			return false;
		$page = "";
		while ( $buf = fread($fd, 1000) )
			$page .= $buf;
	
		# $regexp = '/<a\s+href="([^"]+)"\s+>([^>]+)<\/a>/i';
		$regexp = '/<a\s+href="([^"]+)"\s*>([^>]+)<\/a>/i';
		preg_match_all($regexp, $page, $urls, PREG_SET_ORDER);
		
		echo "<table><tr><th>Текст ссылки</th><th>Адрес ссылки</th>";
		foreach ($urls as $ref)
			echo "<tr> <td>{$ref[2]}</td> <td>{$ref[1]}</td> <td><a href=\"{$ref[1]}\">перейти</a></td> </tr>";
		echo "</table>";
		return true;
	}

?>

<form method="GET" action="<?php echo $_SERVER["PHP_SELF"]; ?>">
	<h3>Введите адрес страницы</h3>
	http://<input type="text" name="url" size="100" value="<?php if (isset($_GET['url'])) echo $_GET['url']; ?>" />
	<input type="submit" value="Показать" />
</form>

<?php
	if ( isset($_GET['url']) && !parse_links( 'http://' . $_GET['url'] ) )
		echo "<font color=\"#FF0000\">Невозможно загрузить страницу</font>";

	include($_SERVER["DOCUMENT_ROOT"] . "/php/footer.inc");
?>
