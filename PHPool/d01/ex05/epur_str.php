#!/usr/bin/php
<?php
	
	function ft_split_for_epur($str)
	{
		$str = trim($str);
		$splited = explode(" ", $str);
		$splited = array_filter($splited);
		$splited = array_values($splited);
		return($splited);
	}

	if ($argc != 2)
		return;
	$array = ft_split_for_epur($argv[1]);
	$size = count($array);
	for ($i = 0; $i != $size; $i++)
	{
		echo $array[$i];
		if (($i + 1) != $size)
			echo " ";
	}
	echo "\n";
?>
