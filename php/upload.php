<?php
	include ( $_SERVER['DOCUMENT_ROOT'] . '/php/title.inc');

?>

<form method="POST" action="<?php echo $_SERVER['PHP_SELF']; ?>" enctype="multipart/form-data">
	<input type="file" name="file" /><br/>
	<input type="submit" name="submit" value="Загрузить">
</form>

<?php
	if (isset($_FILES['file']))
	{
		$data = "";
		$fd = fopen($_FILES['file']['tmp_name'], "r");
		while ( $buf = fread($fd, 1024) )
			$data .= $buf;
		fclose($fd);
		$data = htmlspecialchars($data);
		echo "<table><tr><td>Name</td><td>{$_FILES['file']['name']}</td></tr>
			     <tr><td><Type/td><td>{$_FILES['file']['type']}</td></tr>
			     <tr><td>Tmp name</td><td>{$_FILES['file']['tmp_name']}</td></tr>
			     <tr><td>Size</td><td>{$_FILES['file']['size']}</td></tr>
			     <tr><td>Data</td><td>$data</td></tr></table>";
	}

	include ( $_SERVER['DOCUMENT_ROOT'] . '/php/footer.inc');
?>
