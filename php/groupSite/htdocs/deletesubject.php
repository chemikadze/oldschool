<?php
	require_once("../includes/init.php");
	require_once("../includes/common.php");
	require_once("../includes/subjects.php");

	try
	{
		init();
		if (!(isset($_GET['id']) && is_numeric($_GET['id'])))
			throwException($errors['DATA']);
		if (!($user->access > 1))
			throwException($errors['PERM']);
			
		if (isset($_POST['iamshure']))
		{
			if (deleteSubject($_GET['id']))
			{
				redirect(HOMEPAGE . '/deleted.php');
				exit;
			}
			else
				throwException($errors['DATA']);
		}

		$smarty->assign('title_suffix', '');
		$smarty->display('head.tpl');

		$smarty->assign('question', 'Действительно удалить раздел?');
		$smarty->display('ask.tpl');

		$smarty->display('foot.tpl');
	}
	catch (Exception $e)
	{
		$smarty->displayError($e->getMessage());
	}

?>
