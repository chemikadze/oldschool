<?php
	require_once("../includes/init.php");
	require_once("../includes/common.php");
	require_once("../includes/register.php");

	try
	{
		init();
		$err_str = '';

		if (isset($user->username))
		{
			$smarty->assign('title_suffix', '');
			$smarty->display('head.tpl');
			$smarty->displayError('Чтобы зарегистрироваться, надо выйти.');
			$smarty->display('foot.tpl');
			exit;
		}

		if (isset($_GET['action']) && $_GET['action']=='register')
		{
			$username = register($err_str);
			if ( is_string($username) )
			{
				$_POST['login'] = $_POST['username'];
				$user->login();
				redirect(HOMEPAGE . '/userinfo.php?username=' . $username);
			}
		}
		
		$smarty->assign('title_suffix', '');
		$smarty->display('head.tpl');
		
		if ( $err_str )
			$smarty->assign('reg_error_string', $err_str);

		$smarty->display('register.tpl');
		$smarty->display('foot.tpl');
	}
	catch (Exception $e)
	{
		$smarty->displayError($e->getMessage());
	}

?>
