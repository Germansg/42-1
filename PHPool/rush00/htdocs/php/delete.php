<?php
	function del_account_max($login)
	{
		$swag = file_get_contents("private/passwd");
		$unserialized = unserialize($swag);
		$i = 0;
		while ($unserialized[$i])
		{
			if ($unserialized[$i]['login'] === $login)
			{
				unset($unserialized[$i]);
				$to_put = serialize($unserialized);
				file_put_contents("private/passwd", $to_put);
				$_SESSION['message'] = "Compte supprimé\n";
				return TRUE;
			}
			$i = $i + 1;
		}
		$_SESSION['message'] = "Erreur de fdp.";
		return FALSE;
	}
//	del_account_max($_POST['oldlogin']);
//	header("Location: http://rush00.local.42.fr:8080/admin_max.php?change_log=mv+%5B...%5D");
?>