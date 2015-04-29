<?php

	if ($_POST['login'] == "" || $_POST['oldpw'] == "" || $_POST['newpw'] == "" || $_POST['submit'] != "OK")
	{
		echo "ERROR\n";
		return ;
	}
	$hashed_oldpw = hash("whirlpool", $_POST['oldpw']);
	$hashed_newpw = hash("whirlpool", $_POST['newpw']);
	$swag = file_get_contents("../private/passwd");
	$unserialized = unserialize($swag);
	$i = 0;
	$changed = 0;
	while ($unserialized[$i])
	{
		if ($unserialized[$i]['login'] === $_POST['login'])
		{
			if ($unserialized[$i]['passwd'] === $hashed_oldpw)
			{
				$unserialized[$i]['passwd'] = $hashed_newpw;
				$changed = 1;
			}
			else
			{
				echo "ERROR\n";
				return ;
			}
		}
		$i = $i + 1;
	}
	if ($changed === 1)
	{
		$to_put = serialize($unserialized);
		file_put_contents("../private/passwd", $to_put);
	}
	else
	{
		echo "ERROR\n";
		return ;
	}
	echo "OK\n";
?>
