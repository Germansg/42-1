#!/usr/bin/php
<?php
if ($argc > 2)
{
    $to_find = $argv[1];
    foreach ($argv as $key => $value)
    {
        if ($key > 1)
        {
                $tab = explode(":", $value);
            if ($tab[0] === $to_find)
            {
                $result = $tab[1];
            }
        }
    }
    echo $result;
}
?>