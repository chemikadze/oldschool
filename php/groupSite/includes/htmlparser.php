<?php
	require_once('common.php');


	$good_tags = array(
		'br', 
		'b','i','u','s',
		'ul', 'ol', 'li',
		'a',
		'h1','h2','h3','h4','h5',
		'img'
	);

	$good_tags_all = '<br><b><i><u><s><ul><ol><li><a><h1><h2><h3><h4><h5><img>';

	function parse_html($input)
	{
		global $good_tags_all;
		return strip_tags($input, $good_tags_all);
	}

// maybe some reg-fu?
	function parse_html_my($input)
	{
		global $good_tags;
		$output="";
		$len = strlen($input);
		for ($i=0; $i < $len; $i++)
		{
			if ( $input{$i} != '<' &&  $input{$i} != '>' )
				$output .= $input{$i};
			elseif ($input{$i} == '<')
			{
				$close = false;
				$tag = '';
				if (($i+1)<$len && $input{$i+1}=='/') 
				{
					$i++;
					$close = true;	
				}
				for (++$i; $i < $len && $input{$i}!=' ' && $input{$i}!='>'; $i++)
					$tag .= $input{$i};
				if (in_array($tag, $good_tags))
				{
					if ($close == false)
						$output .= "<$tag";
					else
						$output .= "</$tag";
					while ($input{$i-1} != '>' && $i <= $len)
						$output .= $input{$i++};
					$i--;
				}
				else
				{
					while ($input{$i-1} != '>' && $i <= $len)
						$i++;
					$i--;
				}
			}
		}
		return $output;
	}
?>
