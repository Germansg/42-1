<?php
session_start();

// A FAIRE fonction GET_TYPE_MENU

function get_type_menu($tab, $type_name, $done)
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


function actualisation_html($stock)
{
	//div menu_general //
	$value = 1;
	$value_categorie = -1;
	echo "<div class='menu_general'>\n";
	echo "<form method='post' action='index.php'>\n";
	echo "<ul id='menu'>\n";
	echo "<li><button class='button_menu' href='index.php' name='aff' value='$value_categorie'>Unix</button>\n";
	echo "<ul>\n";
	$done = NULL;
	$tab = get_type_menu($stock, 'Unix', $done);
	$done[] = 'Unix';
	if ($tab)
		$value_categorie--;	
	foreach ($tab as $key)
	{
		echo "<li><button href='index.php' name='aff' value='$value'>";
		echo $key['name'];
		echo "</button></li>\n";
		$value++;
	}
	echo "</ul>\n";
	echo "<li><button class='button_menu' href='index.php' name='aff' value='$value_categorie'>Graphics</button>\n";
	echo "<ul>\n";
	$tab = get_type_menu($stock, 'Graphics', $done);
	$done[] = 'Graphics';
	if ($tab)
		$value_categorie--;	
	foreach ($tab as $key)
	{
		echo "<li><button href='index.php' name='aff' value='$value'>";
		echo $key['name'];
		echo "</button></li>\n";
		$value++;
	}
	echo "</ul>\n";
	echo "<li><button class='button_menu' href='index.php' name='aff' value='$value_categorie'>Algorithms</button>\n";
	echo "<ul>\n";
	$tab = get_type_menu($stock, 'Algorithms', $done);
	$done[] = 'Algorithms';
	if ($tab)
		$value_categorie--;	
	foreach ($tab as $key)
	{
		echo "<li><button href='index.php' name='aff' value='$value'>";
		echo $key['name'];
		echo "</button></li>\n";
		$value++;
	}
	echo "</ul>\n";
	while (($tab = get_type_menu($stock, 'Other', $done)) != NULL)
	{	
		$type = $tab[0]['type'];
		$done[] = $type;
		echo "<li><button class='button_menu' href='index.php' name='aff' value='$value_categorie'>$type</button>\n";
		echo "<ul>\n";
		foreach ($tab as $key)
		{
			echo "<li><button href='index.php' name='aff' value='$value'>";
			echo $key['name'];
			echo "</button></li>\n";
			$value++;
		}
		echo "</ul>\n";
		$value_categorie--;
	}
	echo "</li>\n";
	echo "</ul>\n";	
	echo "</form>\n";
	echo "</div>\n";
	//end div //

	//DIV general_products //
	$value = 1;
//	$_SESSION['aff'] = 0;
	$value_categorie = -1;
	echo "<div class='general_products'>\n";
	$done = NULL;
	$tab = get_type_menu($stock, 'Unix', $done);
	$done[] = 'Unix';
	$max_value = $value + count($tab);
//	print_r($tab);
	$i = 0;
	while ($value < $max_value)
	{
		if ($_SESSION['aff'] == $value_categorie || $_SESSION['aff'] == $value || $_SESSION['aff'] === 0)
		{
			echo "<div class='product'>\n";
			echo "<div class='";
			if ($tab[$i]['med_type'] == 'vid')
			{
				echo "video'>\n";
				echo "<iframe class='vid' src='";
				echo $tab[$i]['med_value'];
				echo "' frameborder='0' allowfullscreen></iframe>\n";
			}
			else
			{
				echo "img'>\n";
				echo "<img class='img' src='";
				echo $tab[$i]['med_value'];
				echo "'></img>\n";
			}
			echo "</div>\n";
			echo "<div class='description'>\n";
			echo $tab[$i]['description']."\n";
			echo "<br /> <br /> Prix = ".$tab[$i]['prix']."€\n";
			echo "<form method='post' action='index.php'>";
			echo "<input type='hidden' name='nom'  value='".$tab[$i]['name']."' >";
			echo "<input type='submit' name='ajouter_id='";
			echo $value;
			echo "' value='ajouter'>\n";
			echo "</div>\n";
			echo "</div>\n";
		}
		$value++;
		$i++;
	}
	$value_categorie--;
	$tab = get_type_menu($stock, 'Graphics', $done);
	$done[] = 'Graphics';
	$max_value = $value + count($tab);
	$i = 0;
	while ($value < $max_value)
	{
		if ($_SESSION['aff'] == $value_categorie || $_SESSION['aff'] == $value || $_SESSION['aff'] === 0)
		{
			echo "<div class='product'>\n";
			echo "<div class='";
			if ($tab[$i]['med_type'] == 'vid')
			{
				echo "video'>\n";
				echo "<iframe class='vid' src='";
				echo $tab[$i]['med_value'];
				echo "' frameborder='0' allowfullscreen></iframe>\n";
			}
			else
			{
				echo "img'>\n";
				echo "<img class='img' src='";
				echo $tab[$i]['med_value'];
				echo "'></img>\n";
			}
			echo "</div>\n";
			echo "<div class='description'>\n";
			echo "<div class='description'>\n";
			echo $tab[$i]['description']."\n";
			echo "<br /> <br /> Prix = ".$tab[$i]['prix']."€\n";
			echo "<form method='post' action='index.php'>";
			echo "<input type='hidden' name='nom'  value='".$tab[$i]['name']."' >";
			echo "<input type='submit' name='ajouter_id='";
			echo $value;
			echo "' value='ajouter'>\n";
			echo "</div>\n";
			echo "</div>\n";
		}
		$value++;
		$i++;
	}
	$value_categorie--;
	$tab = get_type_menu($stock, 'Algorithms', $done);
	$done[] = 'Algorithms';
	$max_value = $value + count($tab);
	$i = 0;
	while ($value < $max_value)
	{
		if ($_SESSION['aff'] == $value_categorie || $_SESSION['aff'] == $value || $_SESSION['aff'] === 0)
		{
			echo "<div class='product'>\n";
			echo "<div class='";
			if ($tab[$i]['med_type'] == 'vid')
			{
				echo "video'>\n";
				echo "<iframe class='vid' src='";
				echo $tab[$i]['med_value'];
				echo "' frameborder='0' allowfullscreen></iframe>\n";
			}
			else
			{
				echo "img'>\n";
				echo "<img class='img' src='";
				echo $tab[$i]['med_value'];
				echo "'></img>\n";
			}
			echo "</div>\n";
			echo "<div class='description'>\n";
			echo $tab[$i]['description']."\n";
			echo "<br /> <br /> Prix = ".$tab[$i]['prix']."€\n";
			echo "<form method='post' action='index.php'>";
			echo "<input type='hidden' name='nom'  value='".$tab[$i]['name']."' >";
			echo "<input type='submit' name='ajouter_id='";
			echo $value;
			echo "' value='ajouter'>\n";
			echo "</div>\n";
			echo "</div>\n";
		}
		$value++;
		$i++;
	}
	$value_categorie--;
	while (($tab = get_type_menu($stock, 'Other', $done)) != NULL)
	{
		$done[] = $tab[0]['type'];
		$max_value = $value + count($tab);
		$i = 0;
		while ($value < $max_value)
		{
			if ($_SESSION['aff'] == $value_categorie || $_SESSION['aff'] == $value || $_SESSION['aff'] === 0)
			{
				echo "<div class='product'>\n";
				echo "<div class='";
				if ($tab[$i]['med_type'] == 'vid')
				{
					echo "video'>\n";
					echo "<iframe class='vid' src='";
					echo $tab[$i]['med_value'];
					echo "' frameborder='0' allowfullscreen></iframe>\n";
				}
				else
				{
					echo "img'>\n";
					echo "<img class='img' src='";
					echo $tab[$i]['med_value'];
					echo "'></img>\n";
				}
				echo "</div>\n";
				echo "<div class='description'>\n";
				echo $tab[$i]['description']."\n";
				echo "<br /> <br /> Prix = ".$tab[$i]['prix']."€\n";
				echo "<form method='post' action='index.php'>";
				echo "<input type='hidden' name='nom'  value='".$tab[$i]['name']."' >";
				echo "<input type='submit' name='ajouter_id='";
				echo $value;
				echo "' value='ajouter'>\n";
				echo "</div>\n";
				echo "</div>\n";
			}
			$value++;
			$i++;
		}
		$value_categorie--;
	}
	echo "</div>\n";
}
?>