<?php
	require_once("../includes/init.php");
	require_once("../includes/common.php");
	require_once("../includes/article.php");

	try
	{
		init();
		$smarty->assign('title_suffix', '');
		$smarty->display('head.tpl');

		$comm_err = '';
		if ( (((!(isset($_POST['comment_submit']) && isset($_GET['id']))) && is_numeric($_GET['id'])) 
					|| postComment($_GET['id'], $comm_err)) &&
 			 (!$comm_err && isset($_GET['id']) && is_numeric($_GET['id']) && 
			 		$article = getArticle($_GET['id'])) )
		{
			$smarty->assign('article', $article);
			$smarty->display('article.tpl');
		}
		else
			$smarty->displayError( $comm_err ? $comm_err : $errors['NOART'] );
		$smarty->display('foot.tpl');
	}
	catch (Exception $e)
	{
		$smarty->displayError($e->getMessage());
	}

?>
