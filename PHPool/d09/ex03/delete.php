<?php
	if (file_exists("list.csv") && isset($_GET["val"]))
	{
		$tab = explode(":", $_GET["val"]);
		$str = '';
		for ($i = 0; $i < count($tab); ++$i)
		{
			if ($tab[$i] != '')
				$str .= $i.";".$tab[$i].PHP_EOL;
		}
		file_put_contents("list.csv", $str);
	}
?>