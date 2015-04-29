#!/usr/bin/php
<?php
while(1)
{
    echo "Entrez un nombre:";
    if ($line = fgets(STDIN))
    {
        $line = rtrim($line);
        $ok = 0;
        if (!is_numeric($line))
        {

            $ok = 1;
            $line2 = $line;
        }
        $line = intval($line);
        $limit = 9223372036854775807;
        if ($ok == 1)
        {
            echo "'".$line2."' n'est pas un chiffre\n";
        }
        else if ($line == $limit || $line == -9223372036854775808)
        {
            echo "Error: le nombre et trop grand.\n";
        }
        else if ($line % 2 == 0)
        {
            echo "Le chiffre ".$line." est Pair\n";
        }
        else
        {
            echo "Le chiffre ".$line." est Impair\n";
        }
    }
    else
    {
        echo "\n";
        return;
    }
}
?>