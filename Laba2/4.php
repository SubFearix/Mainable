<?php
echo "Введите числа через пробел: ";
$input = trim(fgets(STDIN)); // Считываем всю строку
$nums = explode(' ', $input); // Разбиваем строку на числа
$count = 0;
foreach ($nums as $num) {
    $st = strval(abs($num)); // Преобразовываем число в строку
    if (strlen($st) % 2 != 0) { // Считаем длину строки
        $count++;
    }
}
echo $count;
?>
