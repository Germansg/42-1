<?php
function check_admin($log)
{
	$tab = ["tam", "sammi", "souf", "max", "admin"];
	foreach ($tab as $key)
	{
		if ($key == $log)
			return (TRUE);
	}
	return (FALSE);
}

?>