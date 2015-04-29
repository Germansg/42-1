<?php
	function auth($login, $passwd)
	{
		$swag = file_get_contents("../private/passwd");
		$unserialized = unserialize($swag);
		$hashed_pwd = hash("whirlpool", $passwd);
		$i = 0;
		while ($unserialized[$i])
		{
			if ($unserialized[$i]['login'] === $login)
			{
				if ($unserialized[$i]['passwd'] === $hashed_pwd)
				{
					return TRUE;
				}
				else
				{
					return FALSE;
				}
			}
			$i = $i + 1;
		}
		return FALSE;
	}
?>
