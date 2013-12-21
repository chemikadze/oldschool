<?php
	require_once("../includes/init.php");
	require_once("../includes/common.php");
	require_once("../includes/userinfo.php");

	try
	{
		init();
		$smarty->assign('title_suffix', '');
		$smarty->display('head.tpl');
		
		unset($username);
		if (isset($_GET['username']))
			$username = $_GET['username'];
		elseif (isset($user->username))
			$username = $user->username;
			
		if (isset($username))
		{
			if ($userinfo=getUserinfo($username))
			{
				$smarty->assign('userinfo', $userinfo);
				$smarty->display('userinfo.tpl');
			}
			else
				$smarty->displayError($error['UNKUSER']);
		}
		else
			$smarty->displayError($error['404']);

		$smarty->display('foot.tpl');
	}
	catch (Exception $e)
	{
		$smarty->displayError($e->getMessage());
	}

?>
