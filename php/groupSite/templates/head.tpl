<?xml version='1.0' encoding='UTF-8'?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
{config_load file="config.cfg"}
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" >
		<title>Сайт группы {#GROUP#} {$title_suffix}</title>
		<link rel="stylesheet" href="{#SITE_ROOT#}/main.css" type="text/css" />
	</head>
	<body>
		<center>
			<table class="mainTable" cellspacing=0>
				<tr class="headerRow">
					<td class="headerCell"><a href="{#SITE_ROOT#}" class="homeLink">{#GROUP#}</a></td>
					
					<td class="headerLoginCell" colspan="2">
					{if (!isset($userobj->username))}
						<form action="{$smarty.server.PHP_SELF}?{$smarty.server.QUERY_STRING}" method="POST">
							<input type="hidden" name="lgnAction" value="login" />
							<table class="loginTable" align=right>
								<tr>
									<td>
										Логин:<input type="text" class="loginFormControl" name='login' />
									</td>
									<td>
										Пароль:<input type="password" class="loginFormControl" name='password' />
									</td>
									<td>
										<input type="submit" class="loginFormControl" value="Вход" name='login_submit'>
									</td>
								</tr>
								<tr>
									<td class="loginTableRegisterLinks">
										<a href="{#SITE_ROOT#}/register.php" class="registerLink">Регистрация</a>
									</td>
									<td class="loginTableRegisterLinks">
										<a href="{#SITE_ROOT#}/pass_recovery.php" class="registerLink">Вспомнить пароль</a>
									</td>
									<td class="loginTableRegisterLinks">
										<input type="checkbox" name="remember" value="remember"/>Запомнить
									</td>
								</tr>
							</table>
							</p>
						</form>
					{/if}
					</td>
				


				</tr>
				<tr>
					<td colspan=3 style="padding: 0;">
						<table class="menuBar">
							<tr>
								<td class="menuBarItem"><a href="{#SITE_ROOT#}/index.php" class="menuBarLink">Главная</a></td>
								<td class="menuBarItem"><a href="{#SITE_ROOT#}/subjects.php" class="menuBarLink">Материалы</a></td>
								<td class="menuBarSpacing">
									{if !isset($userobj->username)}
										{if isset($userobj->login_error_str)}Ошибка входа: <font class="enterError">{$userobj->login_error_str}</font>{else}Гость{/if}
									{else}
										<form action="{$smarty.server.PHP_SELF}?{$smarty.server.QUERY_STRING}" method="POST">
											<input type="hidden" name="lgnAction" value="logout" />
											<a href="{#SITE_ROOT#}/userinfo.php?username={$userobj->username}">{$userobj->username}</a><input class="logoutBtn" type="submit" value="Выход" name="logout_submit" />
										</form>
									{/if}

								</td>
							</tr>
						</table>
					</td>
				</tr>
				<tr class="contentPlace">
					<td colspan=3 class="contentPlace">
						<table class="contentMarkup" cellspacing="0" cellpadding="0">
							<tr>
								<td class="sidebarPlace" cellspacing="0" cellpadding="0">
									<table class="sidebar" cellspacing="0" cellpadding="0">
										<tr><td class="sbHeader">{if $userobj->access > 1}<a href="{#SITE_ROOT#}/subjects.php" class="sbLink">{/if}Разделы{if $userobj->access > 1}</a>{/if}</td></tr>
										<tr><td class="sbRow"><a href="{#SITE_ROOT#}/subject.php">Все</a></td></tr>
									<!-- foreach from=разделы item=раздел here -->
										{foreach from=$subjects item=subjectname key=subjectnum}
											<tr><td class="sbRow"><a href="{#SITE_ROOT#}/subject.php?id={$subjectnum}">{$subjectname}</a></td></tr>	
										{/foreach}
									<!-- /foreach here -->
										<tr><td class="sbHeader">Ссылки</td></tr>
										<tr><td class="sbRow"><a href="http://miigaik.ru/">Сайт МИИГАиК</a></td></tr>
										<tr><td class="sbRow"><a href="http://fpkif.ucoz.ru/">Старый сайт</a></td></tr>
										<tr><td class="sbRow"><a href="http://vkontakte.ru/club4388328">Группа ВКонтакте</a></td></tr>
										<tr><td class="sbRow"><a href="http://pluspi.org/">+π.org</a></td></tr>
										<tr><td class="sbRow"><a href="http://habrahabr.ru/">Хабрахабр</a></td></tr>
										<tr><td class="sbRow"><a href="http://???/">Файл-хостинг</a></td></tr>
										<tr><td class="sbRow"><a href="http://http://imageshack.us/">Фотохостинг</a></td></tr>
									</table>
								</td>
								<td class="content">
