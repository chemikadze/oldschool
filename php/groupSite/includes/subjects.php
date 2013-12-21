<?php
	require_once('common.php');

	function addSubject($name)
	{
		$subject = mysql_real_escape_string(htmlspecialchars($name));
		$query = "INSERT INTO subjects(name) VALUES ('$subject');";
		mysql_query_e($query);
		return true;
	}

	function deleteSubject($id)
	{
		$subject = mysql_real_escape_string($id);
		$query = "DELETE FROM subjects WHERE ID=$id;";
		mysql_query_e($query);
		return true;
	}

	function getSubjectsExtended()
	{
		$query = "SELECT subjects.name, subjects.ID, count(articles.ID) AS articles 
				  FROM subjects LEFT JOIN articles ON articles.subject = subjects.ID
				  GROUP BY subjects.ID, subjects.name
				  ORDER BY subjects.ID;";
		$result = mysql_query_e($query);
		$subjs = array();
		while ( $sub = mysql_fetch_array($result) )
			array_push($subjs, $sub);
		return $subjs;
	}

	function renameSubject($name, $id)
	{
		$name = mysql_real_escape_string(htmlspecialchars($name));
		$id = mysql_real_escape_string(htmlspecialchars($id));
		$query = "UPDATE subjects SET name='$name' WHERE id=$id;";
		mysql_query_e($query);
		return true;
	}
?>
