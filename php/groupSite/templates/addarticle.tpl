<form method="POST" action="{$smarty.server.PHP_SELF}?{$smarty.server.QUERY_STRING}">
	<table class="newArticleTable">
		<tr>
			<td class="inputTitles">Раздел:</td>
			<td>
				<select class="subjectSelect" name="subject">
				{foreach from=$selectsubjects item=subjectname key=subjectnum}
					<option value="{$subjectnum}">{$subjectname}</option>
				{/foreach}
				</select>
			</td>
		</tr>
		<tr>
			<td lass="inputTitles">Тип разметки:</td>
			<td>
				<input type="radio" {if $smarty.post.markup=='b'}checked{/if} name="markup" value="b"/>bb-код
				<input type="radio" {if $smarty.post.markup=='h'}checked{/if} name="markup" value="h"/>html
				<input type="radio" {if $smarty.post.markup=='n' || !isset($smarty.post.markup)}checked{/if} name="markup" value="n"/>без разметки
			</td>
		</tr>
		<tr>
			<td class="inputTitles">Заголовок:</td> 
			<td><input type="text" class="articleTitleInput" name="title" value="{$smarty.post.title}"/></td>
		</td>
		<tr>
			<td class="inputTitles">Текст:</td>
			<td><textarea class="articleTextInput" name="code">{$smarty.post.code}</textarea></td>
		</tr>
<!--	<input type="text" class=""> -->
		<tr>
			<td />
			<td>
				<input type="submit" value="Отправить" name="submit" />
				<input type="submit" value="Предпросмотр" name="submit_preview" />
			</td>
		</tr>
		{if isset($smarty.post.submit_preview)}
		<tr><td colspan=2>Предпросмотр: </td></tr>
		<tr>
			<td colspan=2 class="articleHeader">
				{$preview.title}
			</td>
		</tr>
		<tr>
			<td class="articleText" colspan=2>
				{$preview.text}
			</td>
		</tr>
		{/if}
</form>
