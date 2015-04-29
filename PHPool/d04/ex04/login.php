<?php
	include ("auth.php");
	session_start();
	if ($_GET['login'] && $_GET['passwd'])
	{
		if (auth($_GET['login'], $_GET['passwd']) === FALSE)
		{
			$_SESSION['loggued_on_user'] = "";
			echo "ERROR\n";
			return ;
		}
		$_SESSION['loggued_on_user'] = $_GET['login'];
		echo "OK\n";
		return;
	}
	else
	{
		$_SESSION['loggued_on_user'] = "";
		echo "ERROR\n";
		return ;
	}
?>