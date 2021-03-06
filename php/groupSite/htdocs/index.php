<?php
	require_once("../includes/init.php");
	require_once("../includes/common.php");
	require_once("../includes/subject.php");

	try
	{
		init();
		$smarty->assign('title_suffix', '');
		$smarty->display('head.tpl');
		
		$page = (isset($_GET['page']) && is_numeric($_GET['page'])) ?  $_GET['page'] : 0;

		if ( $subject = getSubject(0, $page) )
		{
			$smarty->assign('subject', $subject);
			$smarty->display('subject.tpl');
		}
		else
			$smarty->displayError($errors['NOSUBJ']);
		
		$smarty->display('foot.tpl');
	}
	catch (Exception $e)
	{
		$smarty->displayError($e->getMessage());
	}

?>
