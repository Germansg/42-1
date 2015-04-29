<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<?php
	echo "<a href='../index.php' style='float: right;' > home </a>";
	function get_type_categorie($tab, $type_name, $done)
	{
		if ($done)
		{
			foreach ($done as $key)
			{
				if ($type_name == $key)
					return (NULL);
			}
		}
		$ret = NULL;
		if ($type_name == "Other")
		{
			$type_name = NULL;
			foreach ($tab as $key)
			{
				if (!in_array($key['type'], $done))
				{
					$type_name = $key['type'];
					break;
				}
			}
			if ($type_name)
			{
				foreach ($tab as $key)
				{
					if ($key['type'] == $type_name)	
						$ret[] = $key;
				}
			}
		}
		else
		{
			foreach ($tab as $key)
			{
				if ($key['type'] == $type_name)	
					$ret[] = $key;
			}
		}
		return ($ret);
	}

	$file = file_get_contents("../private/passwd");
	$str = file_get_contents("../private/config");
	$tab = unserialize($str);
	echo "<html>\n";
	echo "<body style='background-color: black; font-family:Monaco; color:#00FF00;'>\n";
	if ($_POST['submit'] == 'Change')
	{
		include "change_content.php";
		if (strlen($_POST['description']) > 1)
		{
			change_content($_POST['old_name'], $_POST['old_type'], $_POST['name'], $_POST['type'], $_POST['med_type'], $_POST['med_value'], $_POST['prix'], $_POST['description']);
		}
		else
		{
			change_content($_POST['old_name'], $_POST['old_type'], $_POST['name'], $_POST['type'], $_POST['med_type'], $_POST['med_value'],  $_POST['prix'], $_POST['old_desc']);
		}
		$_POST['change_content'] = 'ft_fou_la_merde()';
		$_POST['name'] = NULL;
	}
	if ($_POST['submit'] == 'delete_categorie')
	{
		include "del_content.php";
		$done = NULL;
		if ($tab2 = get_type_categorie($tab, $_POST['type'], $done))
		{
			$done[] = $tab2[0]['type'];
			foreach ($tab2 as $key)
			{
				del_content($key['name'], $key['type']);
			}					

		}
		$_POST['submit_admin'] = 'Admin';
		$_POST['name'] = NULL;	
	}

	if ($_POST['submit'] == 'delete')
	{
		include "del_content.php";
		del_content($_POST['name'], $_POST['type']);
		$_POST['submit_admin'] = 'Admin';
		$_POST['name'] = NULL;	
	}
	if ($_POST['del_content'] == 'rm [...]')
	{
		foreach ($tab as $key)
		{
			echo "<form method='post' action='admin.php'>";							
			echo "projet :";
			echo "<input type='text' name='name' value='".$key['name']."' readonly='true' ></br>";
			echo "<input type='hidden' name='type' value='".$key['type']."'></br>";
			echo "<input type='submit' name='submit' value='delete' > </form>";
		}
		echo "</br>";
		echo "</br>";
		$done = NULL;
		while ($tab2 = get_type_categorie($tab, 'Other', $done))
		{
			echo "<form method='post' action='admin.php'>";							
			echo "Categorie :";
			echo "<input type='text' name='type' value='".$tab2[0]['type']."'></br>";
			echo "<input type='submit' name='submit' value='delete_categorie' > </form>";
			$done[] = $tab2[0]['type'];
		}

	}
	if ($_POST['submit'] == 'Create')
	{
		include "create_content.php";		
		create_content($_POST['name'], $_POST['type'], $_POST['med_type'], $_POST['med_value'], $_POST['desc'], $_POST['prix']);
		$_POST['submit_admin'] = 'Admin';
		$_POST['name'] = NULL;		
	}
	if ($_POST['name'])
	{
		foreach ($tab as $key)
		{
			if ($_POST['name'] == $key['name'])
			{
				echo "<form method='post' action='admin.php'>";
				echo "<input type='hidden' name='old_name' value='".$key['name']."'></br>";
				echo "nom : \n"."<input type='text' name='name' value='".$key['name']."'> </br>";
				echo "<input type='hidden' name='old_type' value='".$key['type']."'></br>";				
				echo "Categorie : \n"."<input type='text' name='type' value='".$key['type']."'></br>";
				echo "type de media (vid/img) : \n"."<input type='text' name='med_type' value='".$key['med_type']."'></br>";
				echo "url / path : \n"."<input type='text' name='med_value' value='".$key['med_value']."'></br>";
				echo "description : ".substr($key['description'], 0, 25)."..."."</br>";
				echo "<input type='hidden' name='old_desc' value='".$key['description']."''> </br>";
				echo "<textarea row='10' cols='50' name='description' value=''> </textarea> </br>";
				echo "prix : \n"."<input type='text' name='prix' value='".$key['prix']."' \$> </br>";				
				echo "<input type='submit' name='submit' value='Change' > </form> </br>";
				echo "</br>";
			}
		}
	}
	if ($_POST['create_content'] == 'touch [...]')
	{
		echo "<form method='post' action='admin.php'>";
		echo "nom : \n"."<input type='text' name='name' value=''> </br>";
		echo "Categorie : \n"."<input type='text' name='type' value=''></br>";
		echo "type de media (vid/img) : \n"."<input type='text' name='med_type' value=''></br>";
		echo "url / path : \n"."<input type='text' name='med_value' value=''></br>";
		echo "<textarea row='10' cols='50' name='desc' value=''> </textarea> </br>";
		echo "prix : \n"."<input type='text' name='prix' value='' \$> </br>";				
		echo "<input type='submit' name='submit' value='Create' > </form> </br>";
		echo "</br>";
	}
	$str = file_get_contents("../private/config");
	$tab = unserialize($str);
	if ($_POST['change_content'] == 'ft_fou_la_merde()')
	{
			foreach ($tab as $key)
			{
				echo "<form method='post' action='admin.php'>";							
				echo "projet :";
				echo "<input type='text' name='name' value='".$key['name']."' readonly='true' ></br>";
				echo "<input type='submit' name='submit' value='check' > </form>";
			}
//		}
	}
	if ($_POST['submit_admin'] == 'Admin')
	{
		echo "<form style='display: inline;' method='post' action='../admin_max.php'>";
		echo "Changer logs     :";
		echo "<input style='display: inline;' type='submit' name='change_log' value='mv [...]' >";
		echo "<br \>";
		echo "<form method='post' action='admin.php'>\n";
		echo "<p> Suprimer contenue    :";
		echo "<input type='submit' name='del_content' value='rm [...]' >\n";
		echo "</p>\n";
		echo "<p> Creer contenue     :";
		echo "<input type='submit' name='create_content' value='touch [...]' >\n";
		echo "</p>\n";
		echo "<p> Changer contenue :";
		echo "<input type='submit' name='change_content' value='ft_fou_la_merde()' >\n";
		echo "</p>\n </form>\n";
	}
	echo "</body>\n";
	echo "</html>\n";
?>