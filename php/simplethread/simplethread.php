<?php
	include( $_SERVER['DOCUMENT_ROOT'] . '/php/title.inc');
?>

<style type="text/css">
	.inputtable {
	//	width: 80%;
	}

	.inputrow {
		background: #AAAAFF;
	}

	.post{
		background: #CCCCFF;
	}

	.postdate{
		text-align: right;
	}

	.postsign{
		color: red;
		text-align: left;
	}

	.posttitle{
		color: green;
		text-align: left;
	}

	.postid{
	}

	.postimg{
	}

	.posttext{
	}

	.postimage{
	}

	.inputedit {
		width: 500;
	}

	.inputtext {
		width: 500;
		height: 100;
	}
</style>

<form method="POST" action="<?php echo $_SERVER['PHP_SELF']; ?>" enctype="multipart/form-data">
<table class="inputtable">
	<tr class="inputrow"><td>Заголовок</td><td><input class="inputedit" type="text" name="title"></td></tr>
	<tr class="inputrow"><td>Подпись</td><td><input class="inputedit" type="text" name="signature"></td></tr>
	<tr class="inputrow"><td>Email</td><td><input class="inputedit" type="text" name="email"></td></tr>
	<tr class="inputrow"><td>Изображение</td><td><input class="inputedit" type="file" name="file"></td></tr>
	<tr class="inputrow"><td>Текст</td><td><textarea class="inputtext" name="text"></textarea></td></tr>
	<tr class="inputrow"><td></td><td><input name="submit" type="submit" value="Отправить"></td></tr>
</table>
</form>

<?php

	function set($data)
	{
		if (isset($data))	return $data;
		else			return "";
	}

	//mysql_connect('localhost', 'chemikadze', 'batkabatka');
	mysql_connect('localhost', 'root', 'mysqljlvby');
	mysql_select_db('simplethread');

	if (isset($_POST['submit']))
	{
		$title = mysql_escape_string(htmlspecialchars(set($_POST['title'])));
		$signature = mysql_escape_string(htmlspecialchars(set($_POST['signature'])));
		$email = mysql_escape_string(htmlspecialchars(set($_POST['email'])));
		$text = mysql_escape_string(htmlspecialchars(set($_POST['text'])));

		if (isset($_FILES['file']))
		{
			$filename = $_FILES['file']['tmp_name'];

			$res = mysql_query("SELECT LOAD_FILE('$filename') AS DATA;");
			$dat = mysql_fetch_array($res);
			echo $dat['DATA'];

			mysql_query("INSERT INTO messages(datetime, title, signature, email, text, file) value (now(), '$title', '$signature', '$email', '$text', LOAD_FILE('$filename'));") or die('Can not insert:' . mysql_error());
			echo "INSERT INTO messages(datetime, title, signature, email, text, file) value (now(), '$title', '$signature', '$email', '$text', LOAD_FILE('$filename'));";
		}
		else 
			mysql_query("INSERT INTO messages(datetime, title, signature, email, text) value (now(), '$title', '$signature', '$email', '$text');") or die('Can not insert:' . mysql_error());
	}

	$result = mysql_query('SELECT ID, datetime, title, signature, email, text, if(file IS NULL, \'nul\', \'ID\') AS img FROM messages ORDER BY datetime;');
	while ( $data = mysql_fetch_array($result, MYSQL_ASSOC) )
	{
		if ($data['signature']==NULL)
			$data['signature'] = 'Сырно';
?>
		<table class="post">
			<tr> 	<td class="postid"><?php echo $data['ID']; ?></td> 
				<td class="postsign"><?php echo $data['signature']; ?></td> 
				<td class="posttitle"> <?php echo $data['title']; ?> </td>
				<td class="postdate"> <?php echo $data['datetime']; ?> </td> </tr>
			<tr>	<td class="postimg"> <?php if ($data['img'] != 'nul') echo '<a href="/php/simplethreadimg.php?id='. $data['ID'] .'"><img class="postimage" src="' . '/php/simplethreadimg.php?id=' . $data['ID'] . '"></a>'; ?> </td> <td class="posttext"> <?php echo $data['text']; ?> </td> </tr>
			
		</table><br>
<?php
	}

	include( $_SERVER['DOCUMENT_ROOT'] . '/php/footer.inc');
?>
