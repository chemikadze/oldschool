<?php
	include("title.inc");

	$dayOfTheWeek = array('Воскресенье', 'Понедельник', 'Вторник', 'Среда', 'Четверг', 'Пятница', 'Суббота');
	$dateArr = getdate(time());
	echo "Сегодня ", $dateArr['mday'], " ", $dateArr['month'], " ", $dateArr['year'], ", ",  $dayOfTheWeek[ $dateArr['wday'] ];
	
	include("footer.inc");
?>
