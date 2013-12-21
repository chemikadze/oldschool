<h3>Переименование раздела</h3>
		<form action = "{$smarty.server.PHP_SELF}?{$smarty.server.QUERY_STRING}" method="POST">
			<input type="text" class="newSubjectName" name="newSubjectName" value="{$subjectname}"/>
			<input type="submit" value="Изменить" name="submit_rename">
		</form>
