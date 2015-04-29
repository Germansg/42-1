#!/usr/bin/php
<?php
function ft_check($arr)
{
       return (count($arr) == 2 && is_numeric(trim($arr[0])) && is_numeric(trim($arr[1])));
}
function ft_add($arr, $neg1, $neg2)
{
       if (!ft_check($arr))
          echo "Syntax Error\n";
       else
       {
         $res1 = (trim($arr[0])) * $neg1;
         $res2 = (trim($arr[1])) * $neg2;
          echo ($res1 + $res2) . "\n";
       }
}
function ft_sub($arr, $neg1, $neg2)
{
       if (!ft_check($arr))
          echo "Syntax Error\n";
       else
       {
         $res1 = (trim($arr[0])) * $neg1;
         $res2 = (trim($arr[1])) * $neg2;
          echo ($res1 - $res2) . "\n";
       }
}
function ft_mlt($arr, $neg1, $neg2)
{
       if (!ft_check($arr))
          echo "Syntax Error\n";
       else
       {
         $res1 = (trim($arr[0])) * $neg1;
         $res2 = (trim($arr[1])) * $neg2;
          echo ($res1 * $res2) . "\n";
       }
}
function ft_div($arr, $neg1, $neg2)
{
       if (!ft_check($arr))
          echo "Syntax Error\n";
       else
       {
         $res1 = (trim($arr[0])) * $neg1;
         $res2 = (trim($arr[1])) * $neg2;
          echo ($res1 / $res2) . "\n";
       }
}
function ft_mod($arr, $neg1, $neg2)
{
       if (!ft_check($arr))
          echo "Syntax Error\n";
       else
       {
         $res1 = (trim($arr[0])) * $neg1;
         $res2 = (trim($arr[1])) * $neg2;
          echo ($res1 % $res2) . "\n";
       }
}
if (count($argv) != 2)
{
  echo "Incorrect Parameters\n";
  return ;
}
$neg1 = 1;
$argv[1] = trim($argv[1]);
if ($argv[1][0] == '-' || $argv[1][0] == '+')
{ 
 if ($argv[1][0] == '-')
   $neg1 = -1;
 $argv[1][0] = '0';
}
$neg2 = 1;
$i = strlen($argv[1]) - 1;
while ($argv[1][$i] >= '0' && $argv[1][$i] <= '9' && $i >= 0)
 $i--;
if ($argv[1][$i] == '-' || $argv[1][$i] == '+')
{
   $j = $i - 1;
   while ($argv[1][$j] == ' ' && $j >= 0)
     $j--;
   $c = $argv[1][$j];
   if ($c == '+' || $c == '-' || $c == '*' || $c == '/' || $c == '%')
   {
       if ($argv[1][$i] == '-')
         $neg2 = -1;
       $argv[1][$i] = '0';
   }
}
if (strchr($argv[1], "+"))
  ft_add(explode("+", $argv[1]), $neg1, $neg2);
else if (strchr($argv[1], "*"))
  ft_mlt(explode("*", $argv[1]), $neg1, $neg2);
else if (strchr($argv[1], "/"))
  ft_div(explode("/", $argv[1]), $neg1, $neg2);
else if (strchr($argv[1], "%"))
  ft_mod(explode("%", $argv[1]), $neg1, $neg2);
else if (strchr($argv[1], "-"))
  ft_sub(explode("-", $argv[1]), $neg1, $neg2);
else
  echo "Syntax Error\n";

?>