<h3>Разделы</h3>
<table class="subjectsList" cellspacing=0>
		<tr>
			<th class="subjNameCell">Название</td>
			<th class="subjPostCountCell">Постов</td>
		</tr>
	{foreach from=$list_subjects item=subj}
		<tr>
			<td class="subjNameCell"><a href="{#SITE_ROOT#}/subject.php?id={$subj.ID}">{$subj.name}</a></td>
			<td class="subjPostCountCell">{$subj.articles}</td>
		{if $userobj->access > 1}
			<td style="padding-left: 10px;"><a href="{#SITE_ROOT#}/renamesubject.php?id={$subj.ID}">переименовать</a></td>
			<td style="padding-left: 10px;"><a href="{#SITE_ROOT#}/deletesubject.php?id={$subj.ID}">удалить</a></td>
		{/if}
		</tr>
	{/foreach}
	{if $userobj->access > 1}
		<form action = "{$smarty.server.PHP_SELF}?{$smarty.server.QUERY_STRING}" method="POST">
			<input type="text" class="newSubjectName" name="newSubjectName"/>
			<input type="submit" value="Добавить" name="submit_new">
		</form>
	{/if}
</table>
