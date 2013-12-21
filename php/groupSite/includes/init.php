<?php
	require_once('common.php');
	require_once("/usr/share/php/smarty/libs/Smarty.class.php");
	require_once("user.php");

	class MySmarty extends Smarty {
		function MySmarty() {
			$this->Smarty();
			$this->template_dir = SITE_ROOT . '/templates';
			$this->compile_dir = SITE_ROOT . '/templates_c';
			$this->cache_dir = SITE_ROOT . '/cache';
			$this->config_dir = SITE_ROOT . '/configs';
		}

		function displayError( $err )
		{
			$this->assign( 'error_string', $err );
			$this->display('error.tpl');
		}
	};

	function getSubjects()
	{
		static $subjects;

		if (!$subjects)
		{	
			$query = "SELECT * FROM subjects ORDER BY ID;";
			$result = mysql_query_e($query);
			$subjects = array();
			while ($subj = mysql_fetch_array($result, MYSQL_ASSOC))
				$subjects[ $subj['ID'] ] = $subj['name'];
		}
		return $subjects;
	}

	function init()
	{
		global $user;
		global $smarty;
		global $errors;
		(mysql_connect('localhost', 'chemikadze', 'batkabatka') &&
 		mysql_select_db('fpkif_site')) or
		throwException($errors['DB'] . mysql_error());
		//mysql_set_time_region('ru_RU');

		session_start();
		session_regenerate_id(true);
		$user = new User();
		if ( isset($_POST['logout_submit']) || !$user->checkSession() )
		{
			if (isset($_POST['login_submit']))
			{
				if ($user->login())
				{
					$time = (isset($_POST['remember']) && $_POST['remember'])*(3600*24*30 + time());
					setcookie('userid', $user->userid, $time);
					setcookie('sessid', $user->sessid, $time);
					$_SESSION['remember'] = $time;
				}
/*				else
				{
					redirect(HOMEPAGE . '/login.php');
					exit;
				}
*/			}
			elseif (isset($_POST['logout_submit']))
				$user->logout();
		}
		else
			$_SESSION['remember'] = (!isset($_SESSION['remember']) || $_SESSION['remember']) && $user->userid ;

		if ($user->userid)
		{
			$time = ((isset($_POST['remember']) && $_POST['remember']) || 
					 (isset($_SESSION['remember']) && $_SESSION['remember'])) * 
					(3600*24*30 + time());
			setcookie('sessid', $user->sessid, $time);
		}

		$subjects = getSubjects();
		$smarty->assign('subjects', $subjects);
		$smarty->assign('userobj', $user);
		return $user;
	}
	
	$user = NULL;
	$smarty = new MySmarty();
?>
