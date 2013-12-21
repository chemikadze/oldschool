<?php
	require_once 'common.php';
	require_once 'htmlparser.php';
	require_once 'bbcodeparser.php';
	
	function getComments($id)
	{
		$m_id = mysql_real_escape_string($id);
		$query = "SELECT comments.*, DATE_FORMAT(time, '%a, %e %M %Y, %T') AS date,
						 users.username AS 'username', users.name AS authorname, users.secondname AS authorsecondname
				  FROM comments LEFT JOIN users ON comments.autor=users.ID
				  WHERE comments.article='$m_id'
				  ORDER BY time DESC;";
		$result = mysql_query_e($query);
		$comments = array();
		while ($comment = mysql_fetch_array($result, MYSQL_ASSOC))
		{
			$comments[ $comment['ID'] ] = $comment;
			print $comment["authorname"];
		}
		return $comments;
	}

	function getArticle($id, $withComments=true)
	{
		$m_id = mysql_real_escape_string($id);
		$query = "SELECT articles.*, DATE_FORMAT(time, '%a, %e %M %Y, %T') AS date,
				  		 users.username AS 'username', users.name AS authorname, users.secondname AS authorsecondname 
				  FROM articles LEFT JOIN users ON articles.autor=users.ID
				  WHERE articles.ID='$m_id';";
		$result = mysql_query_e($query);
		if (!mysql_num_rows($result))
			return false;
		$art = mysql_fetch_array($result, MYSQL_ASSOC);
		if ($withComments)
		{
			$comments = getComments($id);
			$art['commentsarray'] = $comments;
		}
		return $art;
	}

	function getArticleOwnerId($id)
	{
		$m_id = mysql_real_escape_string($id);
		$query = "SELECT autor FROM articles WHERE articles.ID='$m_id';";
		$result = mysql_query_e($query);
		if (!mysql_num_rows($result))
			return NULL;
		return mysql_result($result, 0, 0);
	}

	function postComment($id, & $error)
	{
		global $errors;
		global $user;
		if (!(isset($_POST['markup']) && isset($_POST['comment'])))
			throwException($errors['DATA']);
		if (!$user->userid)
			throwException($errors['PERM']);
		$m_id = mysql_real_escape_string($id);
		$query = "SELECT count(*) FROM articles WHERE ID = $m_id;";
		$result = mysql_query_e($query);
		if (!mysql_result($result, 0, 0))
		{
			$error = $errors['NOART'];
			return false;
		}
		$markup =  $_POST['markup'];
		if		($markup == 'b') $text=parse_bbcode(htmlspecialchars($_POST['comment'], ENT_NOQUOTES));
		elseif  ($markup == 'n') $text=htmlspecialchars($_POST['comment']);
		elseif  ($markup == 'h') $text=parse_html($_POST['comment']);
		else
		{
			throwException($errors['DATA']);
		}
		$text = nl2br($text);
		$text   = mysql_real_escape_string($text);
		$autor  = mysql_real_escape_string($user->userid);
		$query = "INSERT INTO comments(article, autor, text) VALUES ('$m_id', '$autor', '$text');";
		mysql_query_e($query);
		$error = '';
		return true;
	}

	function addArticle( & $error)
	{
		global $errors;
		global $user;

		if (!( isset($_POST['subject']) && isset($_POST['code']) && isset($_POST['markup']) ))
			throwException($errors['DATA']);
		if (!$user->userid)
			throwException($errors['PERM']);

		$subject = mysql_escape_string($_POST['subject']);
		$query = "SELECT count(*) FROM subjects WHERE ID=$subject;";
		$result = mysql_query_e($query);
		if ( !mysql_result($result, 0, 0) )
			throwException($errors['NOSUBJ']);
	
		if (!isset($_POST['title']) || !$_POST['title'])
			$_POST['title'] = 'Без названия';
		$markup =  $_POST['markup'];
		if		($markup == 'b') $text=parse_bbcode(htmlspecialchars($_POST['code'], ENT_NOQUOTES));
		elseif  ($markup == 'n') $text=htmlspecialchars($_POST['code']);
		elseif  ($markup == 'h') $text=parse_html($_POST['code']);
		else
		{
			throwException($errors['DATA']);
		}
		$text = nl2br($text);
		$markup = mysql_real_escape_string($_POST['markup']);
		$title  = mysql_real_escape_string(htmlspecialchars($_POST['title']));
		$code   = mysql_real_escape_string($_POST['code']);
		$text   = mysql_real_escape_string($text);
		$shorttext = $text; // cut correction, use string-functions
		$autor  = mysql_real_escape_string($user->userid);

		$query = "INSERT INTO articles(autor,  subject, title, shorttext, text, code, markup) VALUES 
				  					  ('$autor', '$subject', '$title', '$shorttext', '$text', '$code', '$markup');";
		mysql_query_e($query);
		return mysql_insert_id();
	}

	function getPreview( & $error )
	{
		$markup =  $_POST['markup'];
		
		if (!isset($_POST['code']))
			$_POST['code'] = '';
		if (!isset($_POST['title']) || !$_POST['title'])
			$_POST['title'] = 'Без названия';
		$title = htmlspecialchars($_POST['title']);
		
		if		($markup == 'b') $text=parse_bbcode(htmlspecialchars($_POST['code'], ENT_NOQUOTES));
		elseif  ($markup == 'n') $text=htmlspecialchars($_POST['code']);
		elseif  ($markup == 'h') $text=parse_html($_POST['code']);
		else
		{
			$error = $errors['DATA'];
			return false;
		}
		$text = nl2br($text);
		
		$ret = array('title' => $title, 'text' => $text);	
		return $ret;
	}

	function getSelsubjs($subject = '')
	{
		global $smarty;

		if (!$subject)
		{
			if (!isset($_POST['subject']) && isset($_GET['subject']))
				$subject = $_GET['subject'];
			elseif (isset($_POST['subject']))
				$subject =  $_POST['subject'];
		}

		$subjs = $smarty->get_template_vars('subjects');
		
		$selsubjs = array();
		if ($subject)
			$selsubjs[$subject] = $subjs[$subject];
		
		foreach ($subjs as $subjectid => $subjectname)
			if ($subject != $subjectid)
				$selsubjs[$subjectid] = $subjectname;
		return $selsubjs;
	}

	function editArticle($artid, $err)
	{
		global $errors;
		global $user;

		if (!( isset($_POST['subject']) && isset($_POST['code']) && isset($_POST['markup']) ))
			throwException($errors['DATA']);
		if (!$user->userid)
			throwException($errors['PERM']);

		$artid = mysql_escape_string($artid);

		$subject = mysql_escape_string($_POST['subject']);
		$query = "SELECT count(*) FROM subjects,articles WHERE subjects.ID='$subject' AND articles.ID='$artid';";
		$result = mysql_query_e($query);
		if ( !mysql_result($result, 0, 0) )
			throwException($errors['DATA']);
	
		if (!isset($_POST['title']) || !$_POST['title'])
			$_POST['title'] = 'Без названия';
		$markup =  $_POST['markup'];
		if		($markup == 'b') $text=parse_bbcode(htmlspecialchars($_POST['code'], ENT_NOQUOTES));
		elseif  ($markup == 'n') $text=htmlspecialchars($_POST['code']);
		elseif  ($markup == 'h') $text=parse_html($_POST['code']);
		else
		{
			throwException($errors['DATA']);
		}
		$text = nl2br($text);
		$markup = mysql_real_escape_string($_POST['markup']);
		$title  = mysql_real_escape_string(htmlspecialchars($_POST['title']));
		$code   = mysql_real_escape_string($_POST['code']);
		$text   = mysql_real_escape_string($text);
		$shorttext = $text; // cut correction, use string-functions

		$query = "UPDATE articles 
				  SET subject='$subject', title='$title', shorttext='$shorttext', text='$text', code='$code', markup='$markup' 
				  WHERE ID='$artid';";

		mysql_query_e($query);
		return true;
	}

	function deleteArticle($artid)
	{
		$artid = mysql_real_escape_string($artid);
		$query = "DELETE FROM articles WHERE ID='$artid';";
		mysql_query_e($query);
		$query = "DELETE FROM comments WHERE article='$artid';";
		mysql_query_e($query);
		return true;
	}
?>
