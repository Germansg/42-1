<link rel="stylesheet" href="../style.css" type="text/css"/>
<html>
<body class="admin_background">
<div class="admin_background">
<?php
	echo "<a href='admin_max.php' style='float: right;' > home </a>";
	include ("php/create_account.php");
	$_POST['change_log'] = "mv [...]";
	if ($_POST['add'] != '')
	{
		create_account($_POST['add'], $_POST['passwd'], "OK");
		$_POST['add'] = "";
		$_POST['passwd'] = "";
		$_POST['change_log'] = "mv [...]";
//		header("Location: http://rush00.local.42.fr:8080/../admin_max.php?change_log=mv+%5B...%5D");
	}

	if ($_POST['submit'] == 'modify')
	{
		include "/php/modify_account.php";
		modify_account($_POST['oldlogin3'], $_POST['oldlogin']);
		$_POST['change_log'] = "mv [...]";
		$_POST['add'] = NULL;
	}

	else if ($_POST['submit'] == 'delete')
	{
		include ("php/delete.php");
		echo del_account_max($_POST['oldlogin2']);
//		print_r ($_POST);
		$_POST['change_log'] = 'mv [...]';
		$_POST['add'] = NULL;		

	}

	if ($_POST['change_log'] == "mv [...]")
	{

		$file = file_get_contents("private/passwd");
		$array = unserialize($file);
//		$save = $array;		
		foreach ($array as $key)
		{
			echo "<form  method='post' action='admin_max.php'>";
			echo "<input type='text' name='oldlogin' value='".$key['login']."'>";
			echo "<input type='hidden' name='oldlogin3' value='".$key['login']."'>";
			echo "<input type='submit' name='submit' value='modify' >";
			echo "</form>";
			echo "<form method='post' action='admin_max.php'>";
			echo "<input type='hidden' name='oldlogin2' value='".$key['login']."'>";
			echo "<input type='submit' name='submit' value='delete'></form><br \>";
		}
		echo "<form method='post' action='admin_max.php'>\n";
		echo "<input type='hidden' name='change_log' value='mv [...]'>";
		echo "Login: "."<input class='input_admin' type='text' title='Login' name='add' value=''> <input class='input_admin' title='Password' type='text' name='passwd' value=''> <input type='submit' value='add' ></form>";
	}
?>
</div>
</body>
</html>