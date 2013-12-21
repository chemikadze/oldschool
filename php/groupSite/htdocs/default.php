<?php
	require_once("../includes/init.php");
	require_once("../includes/common.php");
	require_once("../includes/subject.php");

	try
	{
		init();
		$smarty->assign('title_suffix', '');
		$smarty->display('head.tpl');
		// getSubject()
		$smarty->display('subject.tpl');
		$smarty->display('foot.tpl');
	}
	catch (Exception $e)
	{
		$smarty->displayError($e->getMessage());
	}

?>
