#!/usr/bin/php
<?php
  if ($argc == 2)
  {
    function test($tab)
       {  global $argv;
          $recup = $tab[1];
          $dossier = preg_split("/[\/\/|\/]/" , $argv[1]);
          $ta = preg_split("/[\/\/|\/]/" , $recup);
          $nb = count($ta);
          $nb -= 1;
          @mkdir($dossier[2], 0777);
      $handler = fopen($recup, "r");
      $contents = '';
      if($handler)
      {
        while(!feof($handler))
          $contents .= fread($handler, 8192);
        fclose($handler);
        $handlew = fopen($dossier[2]."/".$ta[$nb], "w");
        fwrite($handlew, $contents);
        fclose($handlew);
      }
           return($tab);
       }

    function test2($tab)
       {
        global $argv;
          $str = preg_replace_callback("/src=\"([^\"]*)\"/U", "test", $tab[0]);
           return($str);
       }
    $handle = fopen($argv[1], "r");
    if (FALSE === $handle)
    {
        exit("Failed to open stream to URL");
    }
    while (!feof($handle))
    {
        $contents .= fread($handle, 8192);
    }
     fclose($handle);
     $line = preg_replace_callback("/<img(.|\n)*>/U", "test2", $contents);
  }
?>
