<?php
	require_once("Smarty.class.php");
	
	$smarty = new Smarty();

	$smarty->template_dir = './template/';
	$smarty->compile_dir = './template_c/';
	$smarty->cache_dir = './cache/';

	$smarty->assign('name', 'Chemikadze');

	$smarty->display('index.tpl');
?>
