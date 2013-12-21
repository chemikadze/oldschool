<?php
	require_once("../includes/init.php");
	require_once("../includes/common.php");
	require_once("../includes/article.php");

	try
	{
		init();

		$errorstr = '';
		if (isset($_POST['submit']) && $artid = addArticle($errorstr))
		{
			redirect(HOMEPAGE . '/article.php?id=' . $artid);
			exit;
		}

		$smarty->assign('title_suffix', '');
		$smarty->display('head.tpl');
		
		$selsubjs = getSelsubjs();
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
