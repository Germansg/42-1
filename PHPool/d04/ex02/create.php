<?php

	if ($_POST['login'] == "" || $_POST['passwd'] == "" || $_POST['submit'] != "OK")
	{
		echo "ERROR\n";
		return ;
	}
	$hashed_pwd = hash("whirlpool", $_POST['passwd']);
	if (file_exists("../private") === FALSE)
	{
		$to_save = array();
		$to_save[] = array("login" => $_POST['login'], "passwd" => $hashed_pwd);
		$serialized = serialize($to_save);
		mkdir("../private", 0777);
		file_put_contents("../private/passwd", $serialized);
	}
	else
	{
		$swag = file_get_contents("../private/passwd");
		$unserialized = unserialize($swag);
		$i = 0;
		while ($unserialized[$i])
		{
			if ($unserialized[$i]['login'] === $_POST['login'])
				{
					echo "ERROR\n";
					return ;
				}
			$i = $i + 1;
		}
		$to_add = array("login" => $_POST['login'], "passwd" => $hashed_pwd);
		$unserialized[] = $to_add;
		$to_put = serialize($unserialized);
		file_put_contents("../private/passwd", $to_put);
	}
	echo "OK\n";
?>
