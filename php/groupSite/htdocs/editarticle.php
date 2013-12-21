<?php
	require_once("../includes/init.php");
	require_once("../includes/common.php");
	require_once("../includes/article.php");

	try
	{
		init();
		if (!(isset($_GET['id']) && is_numeric($_GET['id'])))
			throwException($errors['DATA']);
		$artid = $_GET['id'];
		$art = getArticle($_GET['id'], false) or throwException($errors['NOART']);
		if (!($user->access>1 || $user->username==$art['username']))
			throwException($errors['PERM']);
		if (isset($_POST['submit']) && editArticle($artid, $edit_err))
		{
			redirect(HOMEPAGE . '/article.php?id=' . $artid);
			exit;
		}

		$smarty->assign('title_suffix', '');
		$smarty->display('head.tpl');

		foreach ($art as $key => $val)
			if (!isset($_POST[$key]))
				$_POST[$key] = $val;
		
		$selsubjs = getSelsubjs($art['subject']);
		$smarty->assign('selectsubjects', $selsubjs);
		
		if (isset($_POST['submit_preview']))
		{
			$preview = getPreview( $prev_error );
			$smarty->assign('preview', $preview);
		}

		$smarty->display('addarticle.tpl');
		$smarty->display('foot.tpl');
	}
	catch (Exception $e)
	{
		$smarty->displayError($e->getMessage());
	}

?>
