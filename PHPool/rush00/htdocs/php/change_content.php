<?php 
	function change_content($old_n, $old_t, $name, $type, $med_type, $med_value, $prix, $old_desc)
	{
		$str = file_get_contents("../private/config");
		$tab = unserialize($str);
		if (!$name || !$type)
			return ;
		foreach ($tab as $key)
		{
			if ($old_n == $key['name'] && $old_t == $key['type'])
			{
				$replace = ['prix' => $prix, 'name' => $name, 'type' => $type, 'med_type' => $med_type, 'med_value' => $med_value, 'description' => $old_desc];
				$tab2[] = $replace;
			}
			else
			{
				$tab2[] = $key;
			}
		}
		file_put_contents("../private/config", serialize($tab2));
//		header("location : admin.php");		
	}
?> 