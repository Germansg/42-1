<?php

function init_html()
{
	$tab = ['prix' => 42, 'name' => '42sh', 'type' => 'Unix', 'med_type' => 'img', 'med_value' => './img/42sh.png', 'description' => "Dans toute scolarité, il éxiste des moments qui marquent les étudiants pour toujours. Le 42sh est l'un de ces moments. Réaliser ce projet, c'est marquer une étape importante à 42.\n Il s'agit ici d'écrire un shell UNIX le plus stable et le plus complet possible."];
	$tab1 = ['prix' => 80, 'name' => 'Corewar', 'type' => 'Unix', 'med_type' => 'vid', 'med_value' => 'https://www.youtube.com/embed/9P04Eqeqxd4', 'description' => "Le Corewar est un jeu très particulier. Il consiste à rassembler autour d’une 'machine\nvirtuelle' des 'joueurs', lesquels vont y charger des 'champions' qui vont se\nbattre à l’aide de 'processus', dans le but, entre autres, de faire en sorte qu’on dise\nd’eux qu’ils sont 'en vie'."];
	$tab2 = ['prix' => 115, 'name' => 'RootMe', 'type' => 'Unix', 'med_type' => 'img', 'med_value' => './img/rootme.png', 'description' => "Root-Me est un challenge en ligne qui vous propose des épreuves sur le thème de la\nsécurité avec une difficulté graduelle et un environnement adapté, idéal à l’apprentissage.\nNous vous proposons donc de participer à ce challenge en l’intégrant aux projets de l’école.\nL’intégralité des contenus Root-Me sont la propriété de leurs auteurs conformément aux\nmentions légales de root-me.org."];
	$tab3 = ['prix' => 35, 'name' => 'Wolf3D', 'type' => 'Graphics', 'med_type' => 'vid', 'med_value' => 'https://www.youtube.com/embed/hvwUxfNIoks', 'description' => "Ce projet consiste à créer graphiquement la representation schématique d’un terrain en relief en reliant différents points (x, y, z) par des droites. Les coordonnées du terrain seront stockées dans un fichier passé en paramètre."];
	$tab4 = ['prix' => 10, 'name' => 'FDF', 'type' => 'Graphics', 'med_type' => 'vid', 'med_value' => 'https://www.youtube.com/embed/I0Z7S_nZ-rA', 'description' => "Ce projet consiste à créer graphiquement la representation schématique d’un terrain en relief en reliant différents points (x, y, z) par des droites. Les coordonnées du terrain seront stockées dans un fichier passé en paramètre."];
	$tab5 = ['prix' => 250, 'name' => '42 Raytracer', 'type' => 'Graphics', 'med_type' => 'vid', 'med_value' => 'https://www.youtube.com/embed/1JoTZg4Ulo0', 'description' => "Votre objectif est d’être capable, à l’aide de votre programme, de générer des images\nde synthèse selon la méthode du Ray-Tracing. Ces images de synthèse représentent une\nscène, vue d’une position et d’un angle spécifiques, définie par des objets géométriques\nsimples, entiers ou partiels, et disposant d’un système d’éclairage."];

	$tab6 = ['prix' => 100, 'name' => 'Gomoku', 'type' => 'Algorithms', 'med_type' => 'img', 'med_value' => './img/gomoku.png', 'description' => "Le gomoku se joue sur un plateau quadrillé de 19 lignes horizontales et 19 lignes verticales formant, comme un jeu de go, 361 intersections.\nLe but du jeu étant de prendre l'adversaire de vitesse et de réussir le premier à aligner 5 pions de sa couleur, dans les trois directions possibles : vertical, horizontal ou diagonal."];
	$tab7 = ['prix' => 25, 'name' => 'Libasm', 'type' => 'Algorithms', 'med_type' => 'img', 'med_value' => './img/libftasm.png', 'description' => "Le projet libasm a pour but de vous faire coder une minilib en ASM. Vous allez devoir\nrecoder quelques fonctions basiques de la libc afin d’en générer une bibliothèque. A la fin\nde ce projet vous serez familiarisés avec la syntaxe du langage, le fonctionnement de la\nstack, mais aussi le comportement du compilateur."];	
	$tab8 = ['prix' => 20, 'name' => 'Push_swap', 'type' => 'Algorithms', 'med_type' => 'img', 'med_value' => './img/pushswap.png', 'description' => "Le jeu est constitué de 2 piles nommées a et b (si vous savez pas ce qu’est qu'une\npile, Google est votre ami).\nAu départ b est vide et a contient un certain nombre de nombres positifs ou négatifs\n(sans doublons).\nLe but du jeu est de faire en sorte que a contienne les mêmes nombres mais dans\nl’ordre croissant"];
	$tab9 = ['prix' => 20, 'name' => 'Push_swap', 'type' => 'Unix', 'med_type' => 'img', 'med_value' => './img/pushswap.png', 'description' => "Le jeu est constitué de 2 piles nommées a et b (si vous savez pas ce qu’est qu'une\npile, Google est votre ami).\nAu départ b est vide et a contient un certain nombre de nombres positifs ou négatifs\n(sans doublons).\nLe but du jeu est de faire en sorte que a contienne les mêmes nombres mais dans\nl’ordre croissant"];
//	$tab9 = ['prix' => 10, 'name' => 'test1', 'type' => 'Graphics', 'med_type' => 'none', 'med_value' => 'none', 'description' => "nimporte koi "];	
//	$tab10 = ['name' => 'gkfdjngkdfj', 'type' => 'GrosProjets', 'med_type' => 'none', 'med_value' => 'none', 'description' => "Inconnue"];
//	$tab11 = ['name' => 'leo rase toi', 'type' => 'Silteplait', 'med_type' => 'none', 'med_value' => 'none', 'description' => "Inconnue"];	
	$stock[] = $tab;
	$stock[] = $tab1;
	$stock[] = $tab2;
	$stock[] = $tab3;
	$stock[] = $tab4;
	$stock[] = $tab5;
	$stock[] = $tab6;
	$stock[] = $tab7;
	$stock[] = $tab8;								
	$stock[] = $tab9;
//	$stock[] = $tab10;
//	$stock[] = $tab11;
	return ($stock);
}

?>