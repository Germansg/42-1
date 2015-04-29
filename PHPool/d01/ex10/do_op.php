#!/usr/bin/php
<?php

	function ft_split_swag($str)
	{
		$str = trim($str);
		$splited = explode(" ", $str);
		$splited = array_filter($splited);
		$splited = array_values($splited);
		return($splited);
	}
	if ($argc != 4)
	{
		echo "Incorrect Parameters\n";
		return;
	}
	$str1 = implode(" ", $argv);
	$tab = ft_split_swag($str1);
	if ($tab[2] == "+")
		$result = $tab[1] + $tab[3];
	if ($tab[2] == "-")
		$result = $tab[1] - $tab[3];
	if ($tab[2] == "/")
		$result = $tab[1] / $tab[3];
	if ($tab[2] == "*" || $tab[2] == "do_op.php")
		$result = $tab[1] * $tab[3];
	if ($tab[2] == "%")
		$result = $tab[1] % $tab[3];
	echo $result."\n";

?>
