<?php
	
	function ft_split($str)
	{
		$str = trim($str);
		$splited = explode(" ", $str);
		asort($splited);
		$splited = array_filter($splited);
		$splited = array_values($splited);
		return($splited);
	}
?>
