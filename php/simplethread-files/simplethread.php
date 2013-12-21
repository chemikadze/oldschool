<?php
	include( $_SERVER['DOCUMENT_ROOT'] . '/php/title.inc');
?>

<style type="text/css">
	.inputtable {	//	width: 80%;	}
	.inputrow {		background: #AAAAFF;	}
	.post{	background: #CCCCFF;}
	.postdate{		text-align: right;	}	
	.postsign{		color: red;		text-align: left;	}	
	.posttitle{		color: green;		text-align: left;	}	
	.postid{	}	
	.postimg{		max-height: 150px;		max-width: 150px;	margin: 10px;	}	
	.postimgrow{		width: 0%;	}
	.posttext{	vertical-align: top;	text-align: left;	margin: 10px;	}	
	.postimglink{	}	
	.inputedit {		width: 500;	}	
	.inputtext {		width: 500;		height: 100;	}
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

	$images_dir = '/php/simplethread-files/img/';
	mysql_connect('localhost', 'chemikadze', 'batkabatka');
	//mysql_connect('localhost', 'root', '');
	mysql_select_db('simplethread_files');

	if (isset($_POST['submit']))
	{
		$title = mysql_escape_string(htmlspecialchars(set($_POST['title'])));
		$signature = mysql_escape_string(htmlspecialchars(set($_POST['signature'])));
		$email = mysql_escape_string(htmlspecialchars(set($_POST['email'])));
		$text = mysql_escape_string(htmlspecialchars(set($_POST['text'])));

		mysql_query("INSERT INTO messages(datetime, title, signature, email, text) value (now(), '$title', '$signature', '$email', '$text');") or die('Can not insert:' . mysql_error());

		if (isset($_FILES['file']) && $_FILES['file']['error'] == 0)
		{
			$filename = $_FILES['file']['tmp_name'];
			$res = mysql_query('SELECT LAST_INSERT_ID();');
			$imgid = mysql_result($res, 0, 0);
			$imgname = $imgid . '.' . pathinfo($_FILES['file']['name'], PATHINFO_EXTENSION);
			$imgpath = $_SERVER['DOCUMENT_ROOT'] . $images_dir . $imgname;
			$imgthumbpath = $_SERVER['DOCUMENT_ROOT'] . $images_dir . "thumb" . $imgname;

			move_uploaded_file($filename, $imgpath);
			exec("convert $imgpath -geometry 150x150 $imgthumbpath");
			mysql_query("UPDATE messages SET image = '$imgname' WHERE ID = $imgid;");
		}
	}

	$result = mysql_query('SELECT ID, datetime, title, signature, email, text, image FROM messages ORDER BY datetime;');
	while ( $data = mysql_fetch_array($result, MYSQL_ASSOC) )
	{
		if ($data['signature']==NULL)
			$data['signature'] = 'Сырно';
?>
		<table class="post"><tr><td colspan="2">
			<label> <span class="postid"><?php echo $data['ID']; ?></span> 
				<span class="postsign"><?php echo $data['signature']; ?></span> 
				<span class="posttitle"> <?php echo $data['title']; ?> </span>
				<span class="posspanate"> <?php echo $data['datetime']; ?> </span> </label></td></tr>
			<tr><td class="postimgrow"><?php 
					if ($data['image'] != "")
					{
						$image_location = $images_dir . $data['image']; 
						echo '<a href="'.$image_location.'">'. $data['image'].'<br /><img class="postimglink" src="'.$images_dir . 'thumb' . $data['image'] .'"></a>'; 
					}
				?></td>
				<td class="posttext"> <?php echo $data['text']; ?> 
		</td></tr></table><br />
<?php
	}

	include( $_SERVER['DOCUMENT_ROOT'] . '/php/footer.inc');
?>
