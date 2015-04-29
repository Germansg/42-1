<?php

include "actualisation_html.php";
include "init.php";

function display_()
{
	if (file_exists("./private/config"))
	{
	 	$str = file_get_contents("./private/config");
	 	$tab = unserialize($str);
	 	actualisation_html($tab);
	}
	else
	{
		$stock = init_html();
		actualisation_html($stock);
		file_put_contents("./private/config", serialize($stock));
	}
}

?>