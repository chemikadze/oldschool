{if isset($reg_error_string)}
<div class="registerError">
<b>Неверные данные в форме регистрации</b><br />
{$reg_error_string}</div>
{/if}
<h3>Регистрация</h3>
<form action="{#SITE_ROOT#}/register.php?action=register" method="POST">
	<table class="registerTable" cellspacing="0">
	<tr><td colspan="2" class="userinfoHeader">Основное</td></tr>
		<tr>
			<td class="userInfoRowLeft">Логин:</td> <td class="userInfoRowRight"><input class="registerInput" type="text" value="{$smarty.post.username}" name="username" />(*) </td>
		</tr>
		<tr>
			<td class="userInfoRowLeft">Пароль:</td> <td class="userInfoRowRight"><input class="registerInput" type="password" value="" name="password" />(*) </td>
		</tr>
		<tr>
			<td class="userInfoRowLeft">Повторите пароль:</td> <td class="userInfoRowRight"><input class="registerInput" type="password" value="" name="repeatpassword" />(*) </td>
		</tr>
		<tr>
			<td class="userInfoRowLeft">EMail:</td> <td class="userInfoRowRight"><input class="registerInput" type="text" value="{$smarty.post.email}" name="email" />(*) </td>
		</tr>
<!--	<tr><td class="userInfoRowLeft">Аватар:</td> <td class="userInfoRowRight"><input class="registerInput" type="file" name="avatar"></td></tr>	-->
		<tr>
			<td class="userInfoRowLeft">Имя:</td> <td class="userInfoRowRight"><input class="registerInput" type="text" value="{$smarty.post.name}" name="name" /></td>
		</tr>
		<tr>
			<td class="userInfoRowLeft">Фамилия:</td> <td class="userInfoRowRight"><input class="registerInput" type="text" value="{$smarty.post.secondname}" name="secondname" /></td>
		</tr>
		<tr>
			<td class="userInfoRowLeft">Отчество:</td> <td class="userInfoRowRight"><input class="registerInput" type="text" value="{$smarty.post.fathername}" name="fathername" /></td>
		</tr>
		<tr>
			<td class="userInfoRowLeft">Пол:</td>
			<td class="userInfoRowRight">
				<input type="radio" checked name="gender" value="A">не указывать
				<input type="radio" name="gender" value="M">мужской
				<input type="radio" name="gender" value="F">женский
			</td>
		</tr>
	<tr><td colspan=2 class="userInfoGroupFooter"></td></td>
	<tr><td colspan="2" class="userinfoHeader">Контакты</td></tr>
		<td class="userInfoRowLeft">Телефон:</td> <td class="userInfoRowRight"><input class="registerInput" type="text" value="{$smarty.post.phone}" name="phone" /></td>
		<tr>
			<td class="userInfoRowLeft">Домашняя страница:</td> <td class="userInfoRowRight"><input class="registerInput" type="text" value="{$smarty.post.homepage}" name="homepage" /></td>
		</tr>
		<tr>
			<td class="userInfoRowLeft">ICQ:</td> <td class="userInfoRowRight"><input class="registerInput" type="text" value="{$smarty.post.icq}" name="icq" /></td>
		</tr>
		<tr>
			<td class="userInfoRowLeft">Jabber:</td> <td class="userInfoRowRight"><input class="registerInput" type="text" value="{$smarty.post.jabber}" name="jabber" /></td>
		</tr>
		<tr>
	<tr><td colspan=2 class="userInfoGroupFooter"></td></td>
		</tr>
			<td></td> <td><input class="registerSubmit" type="submit" value="Зарегистрировать" /></td>
		</tr>
	</table>
</form>
(*) обязательные поля
