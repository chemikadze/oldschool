<?php
	require_once($_SERVER['DOCUMENT_ROOT'] . "/php/register_example/includes/header.html");
	require_once($_SERVER['DOCUMENT_ROOT'] . "/php/register_example/includes/render.php");
	
	session_start();
	
	database_connect();
	check_login();
	render_session_bar();
	render_user_list();

	require_once("./includes/footer.html");
?>
