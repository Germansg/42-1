#!/usr/bin/php
<?php

	$swag = preg_replace('/[\t\s]+/', ' ', $argv[1]);
	$swag = trim($swag, " ");
	if ($argc > 1)
		echo $swag."\n";

?>
