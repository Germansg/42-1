#!/usr/bin/php
<?php
  if (count($argv) < 2)
    return ;
  $argv[1] = trim($argv[1]);
  date_default_timezone_set("Europe/Paris");
  $j = array("[Ll]undi", "[Mm]ardi", "[Mm]ercredi", "[Jj]eudi", "[Vv]endredi", "[Ss]amedi", "[Dd]imanche");
  $m = array("01" => "[Jj]anvier", "02" => "[Ff][ée]vrier", "03" => "[Mm]ars", "04" => "[Aa]vril", "05" => "[Mm]ai", "06" => "[Jj]uin", "07" => "[Jj]uillet", "08" => "[Aa]oi[uû]t", "09" => "[Ss]eptembre", "10" => "[Oo]ctobre", "11" => "[Nn]ovembre", "12" => "[Dd][ée]cembre");
  $js = implode("|", array_values($j));
  $ms = implode("|", array_values($m));
  if (preg_match("/^(" . $js .") [0-3]?[0-9] (" . $ms . ") [0-9]{4} [0-9]{2}:[0-9]{2}:[0-9]{2}$/", $argv[1]) === 1)
  {
    $split = explode(" ", $argv[1]);
    if ($split[1] !== "0")
    {
      if ($split[1] < 9 && strlen($split[1]) === 1)
        $split[1] = "0" . $split[1];
      $var = -1;
      foreach ($m as $a)
        if (preg_match("/" . $a . "/", $split[2]))
          $var = array_search($a, $m);
      $date = $split[3] . ":" . $var . ":" . $split[1] . " " . $split[4];
      $time = strtotime($date);
      $check = date("Y:m:d G:i:s", $time);
      if ($check == $date && !empty($date))
        echo $time . "\n";
      return ;
    }
  }
  echo "Wrong Format\n";
?>