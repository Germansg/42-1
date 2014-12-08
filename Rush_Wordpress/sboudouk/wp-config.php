<?php
/**
 * La configuration de base de votre installation WordPress.
 *
 * Ce fichier contient les réglages de configuration suivants : réglages MySQL,
 * préfixe de table, clefs secrètes, langue utilisée, et ABSPATH.
 * Vous pouvez en savoir plus à leur sujet en allant sur 
 * {@link http://codex.wordpress.org/fr:Modifier_wp-config.php Modifier
 * wp-config.php}. C'est votre hébergeur qui doit vous donner vos
 * codes MySQL.
 *
 * Ce fichier est utilisé par le script de création de wp-config.php pendant
 * le processus d'installation. Vous n'avez pas à utiliser le site web, vous
 * pouvez simplement renommer ce fichier en "wp-config.php" et remplir les
 * valeurs.
 *
 * @package WordPress
 */

// ** Réglages MySQL - Votre hébergeur doit vous fournir ces informations. ** //
/** Nom de la base de données de WordPress. */
define('DB_NAME', 'db_database');

/** Utilisateur de la base de données MySQL. */
define('DB_USER', 'root');

/** Mot de passe de la base de données MySQL. */
define('DB_PASSWORD', 'rc8fc0');

/** Adresse de l'hébergement MySQL. */
define('DB_HOST', 'localhost');

/** Jeu de caractères à utiliser par la base de données lors de la création des tables. */
define('DB_CHARSET', 'utf8');

/** Type de collation de la base de données. 
  * N'y touchez que si vous savez ce que vous faites. 
  */
define('DB_COLLATE', '');

/**#@+
 * Clefs uniques d'authentification et salage.
 *
 * Remplacez les valeurs par défaut par des phrases uniques !
 * Vous pouvez générer des phrases aléatoires en utilisant 
 * {@link https://api.wordpress.org/secret-key/1.1/salt/ le service de clefs secrètes de WordPress.org}.
 * Vous pouvez modifier ces phrases à n'importe quel moment, afin d'invalider tous les cookies existants.
 * Cela forcera également tous les utilisateurs à se reconnecter.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '&^btf3/}Y[Z&:yKe9R//VMg(#~ U;$+x3$-ax{Qp/-)Q/;ao&lO5,Kw>86l*R.DV');
define('SECURE_AUTH_KEY',  'G[:=Q.1;*-k4)Ac1gdnl;/XmM{e~]F*}_Vx44-He*+0jG[If9,r~,dWJ|0::{/a7');
define('LOGGED_IN_KEY',    '-Z; n:]T!CK84R>8?]W&m<3E4t6J:5,aE;&R0x2<OSxD{:& TiWD:hIGA!(eEwYo');
define('NONCE_KEY',        '|[tq{=Z|F,] =7<WA@Q]gUrwa%98SG6:[iBGs6u5!n(V8S+2#|oaW-QAa*M}|ZjY');
define('AUTH_SALT',        'pjU!;eq*:0hs?{kkYU.-y>N^Y)B 3+OYgfFYly7N@y9$vn4G8Q{U@V3vA*r~m>e@');
define('SECURE_AUTH_SALT', 'sp_;51|~>/rH5^PQ|ps~6&MwNysni~.h,=P+v{.f9Nl;J&O:<Fd,4LJ{Iu#S%pS(');
define('LOGGED_IN_SALT',   ']:Rm7SP]xNAKBtKAwz64`Vl%]xU<tuV+s}aKh7U}_iFRUg#$S>.RU*)+6zyafsq{');
define('NONCE_SALT',       '#)@Ar03vdu-BeiJg|.)&6iDEg`iHhIK!X@2jYz|YK|f_-e-Nb3HNo~um-eKOVTa#');
/**#@-*/

/**
 * Préfixe de base de données pour les tables de WordPress.
 *
 * Vous pouvez installer plusieurs WordPress sur une seule base de données
 * si vous leur donnez chacune un préfixe unique. 
 * N'utilisez que des chiffres, des lettres non-accentuées, et des caractères soulignés!
 */
$table_prefix  = 'wp_';

/** 
 * Pour les développeurs : le mode deboguage de WordPress.
 * 
 * En passant la valeur suivante à "true", vous activez l'affichage des
 * notifications d'erreurs pendant votre essais.
 * Il est fortemment recommandé que les développeurs d'extensions et
 * de thèmes se servent de WP_DEBUG dans leur environnement de 
 * développement.
 */ 
define('WP_DEBUG', false); 

/* C'est tout, ne touchez pas à ce qui suit ! Bon blogging ! */

/** Chemin absolu vers le dossier de WordPress. */
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');

/** Réglage des variables de WordPress et de ses fichiers inclus. */
require_once(ABSPATH . 'wp-settings.php');