<?php
	require_once('common.php');

// TODO: cut?


	$good_tags = array(
		'br', 
		'b',
		'i',
		'u',
		's',
		'ul', // shit...
		'li', // shit...
		'a',
//		'h1','h2','h3','h4','h5',
	);

	function parse_bbcode($input)
	{
		global $good_tags;

		$reg  = array();
		$repl = array();

		foreach ($good_tags as $key=>$tag)
		{
			$reg [$key*2] = "/\[$tag\]/";
			$repl[$key*2] = "<$tag>";
			$reg [$key*2+1] = "/\[\/$tag\]/";
			$repl[$key*2+1] = "</$tag>";
		}

		/// FFFFUUuuuuu
		$n_reg = array(
			'/\[url=(\'|"|)([^"\'\]]+)("|\'|)\]([^\]]*)\[\/url\]/' => '<a href="$2">$4</a>',
			'/\[img=(\'|"|)([^"\'\]]+)("|\'|)\]/'				=> '<img src="$2" alt="$2">',
//			'/"/e' => '\'',
//			'/\[url="([^"]+)"\]([^\]]*)\[\/url\]/' => '<a href="$2">$4</a>',
//			'/\[img="([^"]+)"\]/'				=> '<img src="$2" alt="$2">',
//			'/\[url=\\\'([^\\\']+)\\\']/',
//			'/\[img=\\\'([^\\\']+)\\\']/',
//			'/\[url=([^\"\'\]]+)]([^\]]*)\[\/url\]/'				=> '<a href="$1">$2</a>',
//			'/\[img=([^\"\'\]]+)\]/'								=> '<img src="$1" alt="$1">'
		);

		foreach ($n_reg as $key => $val)
		{
			array_push($reg, $key);
			array_push($repl, $val);
		}

		$input = preg_replace( $reg, $repl, $input );
/*
		$input = preg_replace('/\[url="([^\"]+)"]/', '<a href="$1">' , $input);
		$input = preg_replace('/\[img="([^\"]+)"]/', '<img src="$1" alt="$1">', $input);
		$input = preg_replace('/\[url=\\\'([^\\\']+)\\\']/', '<a href="$1">' , $input);
		$input = preg_replace('/\[img=\\\'([^\\\']+)\\\']/', '<img src="$1" alt="$1">', $input);
		$input = preg_replace('/\[url=([^\"\\\'\]]+)]/', '<a href="$1">' , $input);
		$input = preg_replace('/\[img=([^\"\\\'\]]+)]/', '<img src="$1" alt="$1">', $input);
*/		
//		$input = preg_replace( '/\[[^\]]*\]/', '', $input );

		return $input;
	}
?>
