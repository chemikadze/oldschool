<h3>{$userinfo.username}</h3>
<table class="userinfo" cellspacing="0">
	<tr><td colspan="2" class="userinfoHeader">Основное</td></tr>
	<tr><td class="userInfoRowLeft">Имя:</td> <td class="userInfoRowRight">{$userinfo.name}</td></tr>
	<tr><td class="userInfoRowLeft">Фамилия:</td> <td class="userInfoRowRight">{$userinfo.secondname}</td></tr>
	<tr><td class="userInfoRowLeft">Отчество:</td> <td class="userInfoRowRight">{$userinfo.fathername}</td></tr>
	<tr><td class="userInfoRowLeft">Пол:</td> <td class="userInfoRowRight">{$userinfo.gender_string}</td></tr>
	<tr><td class="userInfoRowLeft">Email:</td> <td class="userInfoRowRight"><a href="mailto:{$userinfo.email}">{$userinfo.email}</a></td></tr>
	<tr><td class="userInfoRowLeft">Уровень доступа:</td> <td class="userInfoRowRight">{$userinfo.access_string}</td></tr>
	<tr><td colspan="2" class="userInfoGroupFooter"></td></td>
	<tr><td colspan="2" class="userinfoHeader">Контакты</td></tr>
	<tr><td class="userInfoRowLeft">Телефон:</td> <td class="userInfoRowRight">{$userinfo.phone}</td></tr>
	<tr><td class="userInfoRowLeft">Домашняя страница:</td> <td class="userInfoRowRight"><a href="{$userinfo.homepage}">{$userinfo.homepage}</a></td></tr>
	<tr><td class="userInfoRowLeft">ICQ:</td> <td class="userInfoRowRight"><a href="http://icq.com/lolwhere/{$userinfo.icq}">{$userinfo.icq}</a></td></tr>
	<tr><td class="userInfoRowLeft">Jabber:</td> <td class="userInfoRowRight">{$userinfo.jabber}</td></tr>
	<tr><td colspan="2" class="userInfoGroupFooter"></td></td>
	<tr><td colspan="2" class="userinfoHeader">Статистика</td></tr>
	<tr><td class="userInfoRowLeft">Количетво постов:</td> <td class="userInfoRowRight">{$userinfo.postcount}</td></tr>
	<tr><td class="userInfoRowLeft">Количетво комментариев:</td> <td class="userInfoRowRight">{$userinfo.commentcount}</td></tr>
	<tr><td colspan="2" class="userInfoGroupFooter"></td></td>
</table>
{if $userobj->username == $userinfo.username }
	<a class="editUserinfo" href="{#SITE_ROOT#}/edituserinfo.php">Редактировать</a><br />
{/if}
