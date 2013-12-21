{if isset($reg_error_string)}
<div class="registerError">
<b>Неверные данные пользователя</b><br />
{$reg_error_string}</div>
{/if}
<h3>Изменение информации о пользователе</h3>
<form action="{$smarty.server.PHP_SELF}" method="POST">
	<table class="registerTable" cellspacing="0">
	<tr><td colspan="2" class="userinfoHeader">Основное</td></tr>
		<tr>
			<td class="userInfoRowLeft">Логин:</td> <td class="userInfoRowRight">{$userinfo.username}</td>
		</tr>
		<tr>
			{if $userobj->access <= 1 || $userobj->username == $userinfo.username}
			<td class="userInfoRowLeft">Старый пароль:</td> <td class="userInfoRowRight"><input class="registerInput" type="password" value="" name="oldpassword" /> (**) </td>
			{/if}
		</tr>
		<tr>
			<td class="userInfoRowLeft">Новый пароль:</td> <td class="userInfoRowRight"><input class="registerInput" type="password" value="" name="newpassword" /></td> <td class="validmsg" id="newpassword"></td>
		</tr>
		<tr>
			<td class="userInfoRowLeft">Повторите пароль:</td> <td class="userInfoRowRight"><input class="registerInput" type="password" value="" name="repeatpassword" /></td> <td class="validmsg" id="repeatpassword"></td>
		</tr>
		<tr>
			<td class="userInfoRowLeft">EMail:</td> <td class="userInfoRowRight"><input class="registerInput" type="text" value="{$userinfo.email}" name="email" /> </td> <td class="validmsg" id="email">
		</tr>
<!--	<tr><td class="userInfoRowLeft">Аватар:</td> <td class="userInfoRowRight"><input class="registerInput" type="file" name="avatar"></td></tr>	-->
		<tr>
			<td class="userInfoRowLeft">Имя:</td> <td class="userInfoRowRight"><input class="registerInput" type="text" value="{$userinfo.name}" name="name" /></td>
		</tr>
		<tr>
			<td class="userInfoRowLeft">Фамилия:</td> <td class="userInfoRowRight"><input class="registerInput" type="text" value="{$userinfo.secondname}" name="secondname" /></td>
		</tr>
		<tr>
			<td class="userInfoRowLeft">Отчество:</td> <td class="userInfoRowRight"><input class="registerInput" type="text" value="{$userinfo.fathername}" name="fathername" /></td>
		</tr>
		<tr>
			<td class="userInfoRowLeft">Пол:</td>
			<td class="userInfoRowRight">
				<input type="radio" {if $userinfo.gender=="A"}checked{/if} name="gender" class="registerInput" value="A">не указывать
				<input type="radio" {if $userinfo.gender=="M"}checked{/if} name="gender" class="registerInput" value="M">мужской
				<input type="radio" {if $userinfo.gender=="F"}checked{/if} name="gender" class="registerInput" value="F">женский
			</td>
		</tr>
	<tr><td colspan=2 class="userInfoGroupFooter"></td></td>
	<tr><td colspan="2" class="userinfoHeader">Контакты</td></tr>
		<tr>
			<td class="userInfoRowLeft">Телефон:</td> <td class="userInfoRowRight"><input class="registerInput" type="text" value="{$userinfo.phone}" name="phone" /></td>
		</tr>
		<tr>
			<td class="userInfoRowLeft">Домашняя страница:</td> <td class="userInfoRowRight"><input class="registerInput" type="text" value="{$userinfo.homepage}" name="homepage" /></td>
		</tr>
		<tr>
			<td class="userInfoRowLeft">ICQ:</td> <td class="userInfoRowRight"><input class="registerInput" type="text" value="{$userinfo.icq}" name="icq" /></td>
		</tr>
		<tr>
			<td class="userInfoRowLeft">Jabber:</td> <td class="userInfoRowRight"><input class="registerInput" type="text" value="{$userinfo.jabber}" name="jabber" /></td>
		</tr>
		<tr>
	<tr><td colspan=2 class="userInfoGroupFooter"></td></td>
		</tr>
			<td>** - не вводите, если не хотите изменять</td> <td><input class="registerSubmit" type="submit" name="submit" value="Изменить" /></td>
		</tr>
	</table>
</form>
