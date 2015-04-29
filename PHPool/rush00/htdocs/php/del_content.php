<?php

	function del_content($name, $type)
	{
		if (!$name || !$type)
			return ;
		$str = file_get_contents("../private/config");
		$tab = unserialize($str);
		foreach ($tab as $key)
		{
			if ($key['name'] == $name && $key['type'] == $type)
			{
				echo "";
			}
			else
				$tab2[] = $key;
		}
		file_put_contents("../private/config", serialize($tab2));
	}
?>