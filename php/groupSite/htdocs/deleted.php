<?php
	require_once("../includes/init.php");
	require_once("../includes/common.php");

	try
	{
		init();
		$smarty->assign('title_suffix', '');
		$smarty->display('head.tpl');
		$smarty->display('articledeleted.tpl');
		$smarty->display('foot.tpl');
	}
	catch (Exception $e)
	{
		$smarty->displayError($e->getMessage());
	}

?>
