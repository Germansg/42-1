
<?php

	session_start();

	include("php/check_logs.php");
	include("php/create_account.php");
	include("php/del_account.php");
	 if ($_POST['del'] == 'del')
	 {
	  foreach ($_SESSION['panier'] as $key => $value)
 	 	{
	 		if ($panier[$key] == $_POST['del_value'])
	 		{
	 			unset($_SESSION['panier'][$key]);
	 			break;
	 		}
		}
	}

	$_SESSION['message_panier'] ="";
	if (!$_SESSION['panier'])
	{
		$_SESSION['panier'] = array();
		$_POST = "";
	}
		// $_SESSION['panier'] = "";
	if (in_array($_POST['nom'], $_SESSION['panier'], TRUE) )
	{
		$_SESSION['message_panier'] = "Déja dans ton panier tricheur !";
	}
	else
		array_push($_SESSION['panier'], $_POST['nom']);
	$_SESSION['message'] = "";
	if ($_POST['aff'] != 0)
		$_SESSION['aff'] = $_POST['aff'];
	else
		$_SESSION['aff'] = 0;
	$_SESSION['message'] = $_SESSION['aff'];
	if (create_account($_POST['login_reg'], $_POST['passwd_reg'], $_POST['submit_reg']) === TRUE)
	{
		$_POST['inscription'] = "";
		$_POST['login_reg'] = "";
		$_POST['passwd_reg'] = "";
		$_POST['submit_reg'] = "";
		$_SESSION['message'] = "Votre compte a été crée avec succès !";
	}
	if ($_POST['delete'] === 'Supprimer mon compte' && $_SESSION['login'] != "")
	{
		del_account($_SESSION['login']);
		$_POST['delete'] = "";
		$_POST['submit'] = 'Déconnexion';
	}
	if ($_POST['submit'] === 'Déconnexion')
	{
		$_SESSION['login'] = "";
		$_SESSION['admin'] = "";
		$_POST['login'] = "";
		$_POST['passwd'] = "";
		$_SESSION['message'] = "Vous êtes maintenant déconnecté ! À la prochaine !";
	}
	if ($_POST['login'] && $_POST['passwd'] && ($_SESSION['login'] == ""))
	{
		if (check_logs($_POST['login'], $_POST['passwd']) === FALSE)
		{
			$_SESSION['login'] = "";
			$_SESSION['message'] = "Mot de passe et/ou login invalide. Veuillez verifier vos identifiants.";
		}
		else
		{
			$_SESSION['login'] = $_POST['login'];
			$_SESSION['message'] = "Vous êtes maintenant connecté , Bienvenue ".$_SESSION['login']."!";
		}
	}

?>

<html>
<head>
	<meta charset="UTF-8" />
	<title>iCheat42</title>

	<link rel="stylesheet" href="style.css" type="text/css"/>
</head>
	<body>
		<div>
			<div class="header">
				<div class="icone">
					<a href="http://rush00.local.42.fr:8080/index.php"><img src="img/icone.png"></a>
				</div>
				<div class="titre">
					<p style="font-size:10px">
					 <?php
					if ($_SESSION['message'] != "")
						echo $_SESSION['message'];
					?>
					<p>iCheat42</p>
					</p>
				</div>
				<div class="log">
				<form method="post" action="index.php">
						<?php if ($_POST['inscription'] != "" && $_SESSION['login'] == ""):?>
							<div class="register">
						<!-- 		<div class="close"></div> -->
	                            <img src="./img/champ.png" class="champs">
								<input type='text' name='login_reg' value='' maxlength="10" class="input_register">
								<input type='password' name='passwd_reg' value='' class="input1_register">
								<input type='text' name='email' value='' class="input1_register">
								<input type='submit' name='submit_reg' value='OK'>
	                        </div>
						<?php elseif ($_SESSION['login'] === ""):?>
							<div class="authentificate_box">
							<!-- 	<div class="close"></div> -->
								<img src="./img/textbox.png" class="authentificate_image">
								<input type='text' name='login' value='' class="input">
								<input type='password' name='passwd' value='' class="input1">
								<input type='submit' name='submit' value='OK'>
								<input type='submit' name='inscription' value='Inscription'>
								<input type='submit' name='panier' value='panier'>

							</div>
						<?php else:?>
							<br />
							<p> Bienvenue à toi <?php echo $_SESSION['login']."\n" ?> </p> <br />
							<input type='submit' name='delete' value='Supprimer mon compte'>
							<input type='submit' name='submit' value='Déconnexion'>
							<input type='submit' name='panier' value='panier'>

					<?php endif; ?>
				</form>
					<?php if ($_SESSION['admin'] === 'ok'): ?>
					<form method="post" action='./php/admin.php'>
					<input type="submit" name="submit_admin" value="Admin">
					</form>
				<?php endif; ?>
				</div>
			</div>
		</div>	
		<?php
				if ($_POST['panier'] === 'panier')
				{
					echo "<div class='panier'><form method='post' action='index.php'>";
					echo "<p>Si le panier est vide, clique sur le hacker pour choisir un cheat !</p>";
					foreach ($_SESSION['panier'] as $value)
					{
						if ($value != "")
							echo "<p>".$value."	<input type='hidden' name='del_value' value'".$value."'><input type='submit' name='del' value='del'></p>";
					}
					echo '</form></div>';
				}
				else
				{
					include "php/config_csv.php";
					display_();
				}
		?>
	</body>
</html>
