<?php

	function create_account($log_to_c, $passwd_to_c, $submit_to_c)
	{
		if ($log_to_c == "" && $passwd_to_c == "" && $submit_to_c == "OK")
		{
			$_SESSION['message'] = "Veuillez saisir une combinaison login/mot de passe valide.";
			return FALSE;
		}
		else if (($log_to_c == "" || $passwd_to_c == "") && $submit_to_c != "OK")
		{
			return FALSE;
		}
		$hashed_pwd = hash("whirlpool", $passwd_to_c);
		if (file_exists("private") === FALSE)
		{
			$to_save = array();
			$to_save[] = array("login" => $log_to_c, "passwd" => $hashed_pwd);
			$serialized = serialize($to_save);
			mkdir("private", 0777);
			file_put_contents("private/passwd", $serialized);
		}
		else
		{
			$swag = file_get_contents("private/passwd");
			$unserialized = unserialize($swag);
			foreach ($unserialized as $key)
			{
				if ($key['login'] === $log_to_c)
				{
					$_SESSION['message'] = "Utilisateur déja existant.";
					return FALSE;
				}
				$tab[] = $key;

			}
			$tab[] = ["login" => $log_to_c, "passwd" => $hashed_pwd];
			file_put_contents("private/passwd", serialize($tab));
		}
		return TRUE; //Votre compte a été crée avec succes ! Bienvenue $_login.
	}
?>
