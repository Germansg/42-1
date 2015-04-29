<?php
Class Color {
    public $red = 0;
    public $blue = 0;
    public $green = 0;
    public static $verbose = False;
    public function __construct(array $kwargs) {
        if (array_key_exists('rgb', $kwargs))
        {
            $this->red = intval(($kwargs['rgb'] >> 0x10) & 0xff);
            $this->blue = intval(($kwargs['rgb'] >> 0x00) & 0xff);
            $this->green = intval(($kwargs['rgb'] >> 0x08) & 0xff);
        }
        else
        {
            if (array_key_exists('red', $kwargs))
                $this->red = intval($kwargs['red']);
            if (array_key_exists('blue', $kwargs))
                $this->blue = intval($kwargs['blue']);
            if (array_key_exists('green', $kwargs))
                $this->green = intval($kwargs['green']);
        }
        if (self::$verbose)
            printf("Color( red: %3.3s, green: %3.3s, blue: %3.3s ) constructed.\n", $this->red, $this->green, $this->blue);
        return;
    }
    public function __destruct() {
        if (self::$verbose)
            printf("Color( red: %3.3s, green: %3.3s, blue: %3.3s ) destructed.\n", $this->red, $this->green, $this->blue);
        return;
    }
    public function __toString() {
        return sprintf("Color( red: %3.3s, green: %3.3s, blue: %3.3s )", $this->red, $this->green, $this->blue);
    }
    public function add(Color $rhs) {
        $color = new Color(array(
            'red' => $this->red + $rhs->red,
            'blue' => $this->blue + $rhs->blue,
            'green' => $this->green + $rhs->green)); 
        return $color;
    }
    public function sub(Color $rhs) {
        $color = new Color(array(
            'red' => $this->red - $rhs->red,
            'blue' => $this->blue - $rhs->blue,
            'green' => $this->green - $rhs->green)); 
        return $color;
    }
    public function mult($f) {
        $color = new Color(array(
            'red' => $this->red * $f,
            'blue' => $this->blue * $f,
            'green' => $this->green * $f));
        return ($color);
    }
    public static function doc() {
        if (file_exists("Color.doc.txt"))
            return (file_get_contents("Color.doc.txt"));
        return;
    }
}
?>
