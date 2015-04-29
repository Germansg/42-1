#!/usr/bin/php
<?php
    if ($argc > 1)
    {
        $fd = @fopen($argv[1], 'r');
        if ($fd === false)
        {
            echo "Error";
            return;
        }
        $line = @fread($fd, filesize($argv[1]));
       function test($tab)
       {
           return strtoupper($tab[0]);
       }
       function test2($tab)
       {
           $str = preg_replace_callback("/>(.|\n)*</U", "test", $tab[0]);
           return($str);
       }
       $line = preg_replace_callback("/\".*\"/U", "test", $line);
       $line = preg_replace_callback("/<a(.|\n)*<\/a>/U", "test2", $line);
       echo $line;
       @fclose($fd);
   }
   return;
?>
