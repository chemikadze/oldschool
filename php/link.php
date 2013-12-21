<?php
	$text = "link is http://example.com/some/lol/\\rrrrr lol";
	
	$urlreg = "/(http:\/\/[^ ]+)/";
	$replacereg = '[url=${1}] ${1} [/url]';

	$replaced = preg_replace($urlreg, $replacereg, $text);

	echo $replaced . "\n";
?>
