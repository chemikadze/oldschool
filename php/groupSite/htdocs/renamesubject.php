
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

		$id = $_GET['id'];
			
		$smarty->assign('title_suffix', '');
		$smarty->display('head.tpl');

		if (!isset($_POST["submit_rename"])) {
			$subjects = $smarty->get_template_vars('subjects'); 
			$subjectname = $subjects[$id];
			$smarty->assign('subjectname', $subjectname);
			$smarty->display('renamesubject.tpl');
		}
		else {
			renameSubject( $_POST[ 'newSubjectName' ], $id );
			redirect( HOMEPAGE . '/subjects.php' );
		}

		$smarty->display('foot.tpl');
	}
	catch (Exception $e)
	{
		$smarty->displayError($e->getMessage());
	}

?>
