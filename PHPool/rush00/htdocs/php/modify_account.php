<?php
	function modify_account($old_login, $new_login)
	{
		$stop = 0;
		if ($old_login == NULL || $new_login == NULL)
			return FALSE;
		else
		{
			if (file_exists("../private/passwd"))
			{
				$file = file_get_contents("../private/passwd");
				$array = unserialize($file);
				foreach ($array as $key)
				{
					if ($key['login'] == $old_login)
					{
						echo "";
					}
					else
						$array2[] = $key;
				}
				file_put_contents("../private/passwd", serialize($array2));
				return TRUE;
			}
			else
				return FALSE;
		}
	}
?>