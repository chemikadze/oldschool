<?php
	require_once("../includes/init.php");
	require_once("../includes/common.php");
	require_once("../includes/article.php");

	try
	{
		init();
		if (!(isset($_GET['id']) && is_numeric($_GET['id'])))
			throwException($errors['DATA']);
		if (!($user->access > 1 || $user->userid === getArticleOwnerId($_GET['id'])))
			throwException($errors['PERM']);
			
		if (isset($_POST['iamshure']))
		{
			if (deleteArticle($_GET['id']))
			{
				redirect(HOMEPAGE . '/deleted.php');
				exit;
			}
			else
				throwException($errors['DATA']);
		}

		$smarty->assign('title_suffix', '');
		$smarty->display('head.tpl');

		$smarty->assign('question', 'Действительно удалить пост?');
		$smarty->display('ask.tpl');

		$smarty->display('foot.tpl');
	}
	catch (Exception $e)
	{
		$smarty->displayError($e->getMessage());
	}

?>
