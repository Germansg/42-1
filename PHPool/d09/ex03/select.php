<?php
	if (file_exists("list.csv"))
	{
		$file = file("list.csv", FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
		$str = '';
		foreach ($file as $line)
			$str .= explode(";", $line)[1].":";
		echo $str;
	}
?>