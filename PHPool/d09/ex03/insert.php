<?php
	if (file_exists("list.csv") && isset($_GET["val"]) && isset($_GET["nbr"]))
		file_put_contents("list.csv", $_GET["nbr"].";".$_GET["val"].PHP_EOL, FILE_APPEND);
?>