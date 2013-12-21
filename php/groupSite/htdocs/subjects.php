<?php
	require_once("../includes/init.php");
	require_once("../includes/common.php");
	require_once("../includes/subjects.php");

	try
	{
		init();
		$smarty->assign('title_suffix', '');
		$smarty->display('head.tpl');

		if (isset($_POST['submit_new'])) {
			addSubject($_POST['newSubjectName']);
		}
	
		$subjs = getSubjectsExtended();
		$smarty->assign('list_subjects', $subjs);
		$smarty->display('subjects.tpl');

		$smarty->display('foot.tpl');
	}
	catch (Exception $e)
	{
		$smarty->displayError($e->getMessage());
	}

?>
