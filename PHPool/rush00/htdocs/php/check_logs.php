<?php
include("check_admin.php");
session_start();
	function check_logs($login, $passwd)
	{
		$swag = file_get_contents("private/passwd");
		$unserialized = unserialize($swag);
		$hashed_pwd = hash("whirlpool", $passwd);
		$i = 0;
		while ($unserialized[$i])
		{
			if ($unserialized[$i]['login'] === $login)
			{
				if ($unserialized[$i]['passwd'] === $hashed_pwd)
				{
					if (check_admin($login) === TRUE)
						$_SESSION['admin'] = 'ok';
					else
						$_SESSION['admin'] = "";
					return TRUE;
				}
				else
				{
					$_SESSION['message'] = "Veuillez saisir une combinaison login/mot de passe valide.";
					return FALSE;
				}
			}
			$i = $i + 1;
		}
		$_SESSION['message'] = "Erreur très très louche.";
		return FALSE;
	}
?>
