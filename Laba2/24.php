<?php
$pos = 0;
$input = trim(fgets(STDIN)); // Считываем всю строку
$nums = explode(' ', $input);
foreach ($nums as $num) {
    $n = abs($num);
    $sum = 0;
    $mult = 1;
    while ($n > 0) {
        $digit = $n % 10;
        $sum += $digit; // Считаем сумму цифр
        $mult *= $digit; // Считаем произведение цифр
        $n = (int)($n / 10);
    }
    if ($sum < $mult) {
        echo $pos . " ";
    }
    $pos++;
}
?>
