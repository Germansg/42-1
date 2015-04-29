<?php
	function create_content($name, $type, $med_type, $med_value, $old_desc, $prix)
	{
		if (!$name || !$type)
			return ;
		$str = file_get_contents("../private/config");
		$tab = unserialize($str);
		$tab[] = ['prix' => $prix, 'name' => $name, 'type' => $type, 'med_type' => $med_type, 'med_value' => $med_value, 'description' => $desc];
		file_put_contents("../private/config", serialize($tab));
	}
?>