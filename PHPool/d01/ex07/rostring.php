#!/usr/bin/php
<?php

	function ft_split_for_rostring($str)
	{
		$str = trim($str);
		$splited = explode(" ", $str);
		$splited = array_filter($splited);
		$splited = array_values($splited);
		return($splited);
	}

	$i = 1;
	$swag = ft_split_for_rostring($argv[1]);
	$size = count($swag);
	if ($size != 0)
	{
		while ($i != $size)
		{
			echo $swag[$i]." ";
			$i++;
		}
		echo $swag[0];
		echo "\n";
	}
?>
