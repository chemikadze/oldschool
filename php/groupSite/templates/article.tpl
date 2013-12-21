<table	class="longArticle" cellspacing="0" cellpadding="0">
	<tr class="articleHeader"><td><a href="{#SITE_ROOT#}/article.php?id={$article.ID}" class="articleHeaderLink">{$article.title}</a></td></tr>
	<tr class="articleText"><td class="articleText">{$article.text}</td></tr>
<!-- need some JavaScript in deleting -->
	<tr class="articleStatusbar">
		<td>Комментариев: {$article.commentsarray|@count}</a>&nbsp;&nbsp;
			Автор: <a href="{#SITE_ROOT#}/userinfo.php?username={$article.username}">{$article.username}</a> ({$article.authorname} {$article.authorsecondname})&nbsp;&nbsp;
			Дата создания: {$article.date}&nbsp;&nbsp;
			{if $userobj->access>0 || $article.username == $userobj->username}
				<a href="{#SITE_ROOT#}/deletearticle.php?id={$article.ID}">Удалить</a>&nbsp;&nbsp;
				<a href="{#SITE_ROOT#}/editarticle.php?id={$article.ID}">Редактировать</a>
			{/if}
		</td> 
	</tr>
</table>
<table class="articleComments" id="comments" cellspacing="0" cellpadding="0">
	{foreach from=$article.commentsarray item=comment}
		<tr>{if isset($comment.avatar)}<td class="articleCommentAvatar" rowspan=2></td>{/if}<td class="articleCommentHeader" {if !isset($comment.avatar)}colspan="2"{/if}><a href="{#SITE_ROOT#}/userinfo.php?username={$comment.username}">{$comment.username}</a> ({$comment.authorname} {$comment.authorsecondname})&nbsp;&nbsp;Дата комментария: {$comment.date}</td></tr>
		<tr><td class="articleCommentText">{$comment.text}</td></tr>
		<tr><td class="articleCommentSpacing" colspan=2></td></tr>
	{foreachelse}
		<tr class="articleCommentNo">
			<td>Комментариев нет</td>
		</tr>
	{/foreach}
</table>
{if $userobj->access>0}
<table class="articleAddComment"  cellspacing="0" cellpadding="0">
	<form method="POST" action="{$smarty.server.PHP_SELF}?{$smarty.server.QUERY_STRING}">
		<tr><td>Оставить комментарий: </td></tr>
		<tr>
			<td>
				<input type="radio" name="markup" value="b" {if $smarty.post.markup=='b'}checked{/if}/>bb-код
				<input type="radio" name="markup" value="h" {if $smarty.post.markup=='h'}checked{/if}/>html
				<input type="radio" name="markup" value="n" {if $smarty.post.markup=='n' || !isset($smarty.post.markup)}checked{/if}/>без разметки
			</td>
		</tr>
		<tr><td><textarea class="articleNewComment" name="comment"></textarea></td></tr>
		<tr><td><input style="width: 100;" type="submit" name="comment_submit" value="Отправить" /></td></tr>
	</form>
</table>
{/if}
