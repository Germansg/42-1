<?php
	function del_account($login)
	{
		$swag = file_get_contents("private/passwd");
		$unserialized = unserialize($swag);
		$i = 0;
		foreach ($unserialized as $key)
		{
			if ($login == $key['login'])
			{
				echo "";
				$i = 1;
			}
			else
				$tab[] = $key;
		}
		file_put_contents("private/passwd", serialize($tab));
		if ($i == 1)
			return (FALSE);
		else
			return (TRUE);
	}
?>
