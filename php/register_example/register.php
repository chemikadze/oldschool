<?php
	
	require_once($_SERVER['DOCUMENT_ROOT'] . "/php/register_example/includes/header.html");
	require_once($_SERVER['DOCUMENT_ROOT'] . "/php/register_example/includes/render.php");
	require_once($_SERVER['DOCUMENT_ROOT'] . "/php/register_example/includes/common.php");
	
	session_start();
	database_connect();
	check_login();
	$result = -1;
	if (isset($_POST['sendRegisterData']))
	{
		if ( $result = process_register_data())
		{
			render_session_bar();
			render_congrats_newbie();
			render_user_info();
		}
	}
	if ( $result <= 0)
	{
		render_session_bar();
		if ( $result == 0 )
			render_incorrect_register_data();
		render_register_form();
	}

	require_once("./includes/footer.html");
?>
