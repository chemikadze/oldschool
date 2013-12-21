<?php
	require_once 'common.php';

	function getSubject($subj, $page)
	{
		$msubj = mysql_real_escape_string($subj);
		if ($subj) {
			$subjwhere = "AND subjects.ID='$msubj'";
		}
		else {
			$subjwhere = '';
		}
		$query = "SELECT count(articles.ID),subjects.name 
				  FROM subjects LEFT JOIN articles ON subjects.ID=articles.subject 
				  WHERE TRUE $subjwhere
				  GROUP BY subjects.id";
		
		$result = mysql_query_e($query);
		if (mysql_num_rows($result)) {
			$artcount = mysql_result($result, 0, 0);
			$subjname = $subj ? mysql_result($result, 0, 1) : "";
		}
		else {
			return false;
		}
		$pagecount = ceil($artcount / SUBJ_PER_PAGE);
		if (!$page || $pagecount < $page)
			$page = $pagecount;
		$count = SUBJ_PER_PAGE;
		$offset = $count * ($pagecount - $page);
		$subjwhere = $subj ? "WHERE subject='$msubj'" : "";
		$query = "SELECT articles.*, DATE_FORMAT(time, '%a, %e %M %Y, %T') AS date,
						users.username, users.name AS authorname, users.secondname AS authorsecondname,
						subjects.name AS subjectname,
						IF(commentcount.comments IS NOT NULL,commentcount.comments,0) AS comments
			   	  FROM ((users RIGHT JOIN articles ON articles.autor=users.ID)
				  		INNER JOIN subjects ON articles.subject=subjects.ID)
						LEFT  JOIN ( 
										SELECT article,count(*) AS comments
										FROM comments
										GROUP BY article
								   ) AS commentcount ON commentcount.article=articles.ID
		 		  $subjwhere
				  ORDER BY time DESC LIMIT $count OFFSET $offset;";

		$result = mysql_query_e($query);
		$articles = array();
		while ( $art = mysql_fetch_array($result, MYSQL_ASSOC) )
		{
			$articles[ $art['ID'] ] = $art;
		}
		
		$subject = array(
			'articles' => $articles,
			'ID' => $subj, 
			'name' => $subjname,
			'page' => $page,
			'pagecount' => $pagecount,
			'navipagecount' => min(3, $pagecount),
			'frompage' => min($pagecount, $page+2 + 2-($page-max(1, $page-2)))+1
		);
		return $subject;
	}
?>
