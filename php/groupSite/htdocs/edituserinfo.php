
<?php
	require_once("../includes/init.php");
	require_once("../includes/common.php");
	require_once("../includes/userinfo.php");

	try
	{
		init();
		$err_str = '';
	
		if (isset($_GET['username']))
			$username = $_GET['username'];
		else
			$username = $user->username;
		if (!$username)
			throw new Exception($errors['404']);
		if ($username != $user->username && $user->access < 2)
			throw new Exception($errors['PERM']);

		if (isset($_POST['submit']) && submitUserinfo($username, $reg_error_str))
			redirect(HOMEPAGE . '/userinfo.php?username=' . $username);		
		$smarty->assign('title_suffix', ': Изменение личной информации.');
		$smarty->display('head.tpl');

		$userinfo = getUserinfo($username);
		if (!$userinfo)
			$smarty->displayError('UNKUSER');
		else
		{
			foreach (array_keys($userinfo) as $key)
			{
				if (isset($_POST[$key]))
					$userinfo[$key] = $_POST[$key];
			}
			if (isset($reg_error_str))
				$smarty->assign('reg_error_string', $reg_error_str);
			$smarty->assign('userinfo', $userinfo);
			$smarty->display('edituserinfo.tpl');
		}
		$smarty->display('foot.tpl');
	}
	catch (Exception $e)
	{
		$smarty->displayError($e->getMessage());
	}

?>
