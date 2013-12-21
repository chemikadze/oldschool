<table class="subjectList" cellspacing=0>
	<tr class="articleMenuBar"><td class="articleMenuBar">{if isset($userobj->username)}<a href="{#SITE_ROOT#}/addarticle.php{if $subject.ID!=0}?subject={$subject.ID}&amp;{/if}">Написать статью</a>{/if}</td></tr>
	<tr><td class="articles">
	{foreach from=$subject.articles item=art}
		<table	class="shortArticle" cellspacing="0" cellpadding="0">
			<tr class="articleHeader"><td><a href="{#SITE_ROOT#}/subject.php?id={$art.subject}" class="articleHeaderLink">{$art.subjectname}</a> → <a href="{#SITE_ROOT#}/article.php?id={$art.ID}" class="articleHeaderLink">{$art.title}</a></td></tr>
			<tr class="articleText"><td class="articleText">{$art.shorttext}</td></tr>
			<tr class="articleStatusbar">
				<td>
					<a href="{#SITE_ROOT#}/article.php?id={$art.ID}#comments">Комментариев: {$art.comments}</a>&nbsp;&nbsp;
					Автор: <a href="{#SITE_ROOT#}/userinfo.php?username={$art.username}">{$art.username}</a> 
					({$art.authorname} {$art.authorsecondname})&nbsp;&nbsp;
					Дата создания: {$art.date}
					{if $userobj->access>1 || $art.username == $userobj->username}
						<a href="{#SITE_ROOT#}/deletearticle.php?id={$art.ID}">Удалить</a>&nbsp;&nbsp;
						<a href="{#SITE_ROOT#}/editarticle.php?id={$art.ID}">Редактировать</a>
					{/if}
				</td> 
			</tr>
		</table>
	{foreachelse}
		<span style="font-size: 16px; font-weight: bold;">Раздел{if isset($subject.name) && $subject.name!=''} "{$subject.name}"{/if} пуст</span>
	{/foreach}
	</td></tr>

	<tr class="naviBar">
		<td>
			<a href="{#SITE_ROOT#}/subject.php?{if $subject.ID!=0}subject={$subject.ID}&amp;{/if}page={$subject.pagecount}" class="naviLink">последняя</a>&nbsp;
	<!-- интересно, верстальщик не о***л бы от такого? -->
			{if ($subject.page+1)<=$subject.pagecount}
				<a class="naviLink" href="{#SITE_ROOT#}/subject.php?{if $subject.ID!=0}subject={$subject.ID}&amp;{/if}page={$subject.page+1}">←</a>&nbsp;
			{else}
				<span class="naviLinkActive">←</span>&nbsp;
			{/if}
			
			{section name=navibar max=$subject.navipagecount loop=$subject.frompage step=-1}
				{if $smarty.section.navibar.index != $subject.page}
					<a class="naviLink" href="{#SITE_ROOT#}/subject.php?{if $subject.ID!=0}subject={$subject.ID}&amp;{/if}page={$smarty.section.navibar.index}">{$smarty.section.navibar.index}</a>&nbsp;
				{else}
					<span class="naviLinkActive">{$smarty.section.navibar.index}</span>&nbsp;
				{/if}
			{/section}

			{if ($subject.page-1)>=1}
				<a class="naviLink" href="{#SITE_ROOT#}/subject.php?{if $subject.ID!=0}subject={$subject.ID}&amp;{/if}page={$subject.page-1}">→</a>&nbsp;
			{else}
				<span class="naviLinkActive">→</span>&nbsp;
			{/if}
			<a class="naviLink" href="{#SITE_ROOT#}/subject.php?{if $subject.ID!=0}subject={$subject.ID}&amp;{/if}page=1">первая</a>
		</td>
	</tr>
</table>
