<?php
echo "Введите n: ";
$n = (int)trim(fgets(STDIN));
if ($n > 0 && $n < 27) { // Проверка на дурака
    for ($i = 1; $i <= $n; $i++) {
        $current = chr(ord('A') + $n - 1); // Текущая буква
        for ($j = 0; $j < $i; $j++) { // Количество повторений в строке
            echo $current;
            if ($j != $i - 1) {
                echo " ";
            }
            $current = chr(ord($current) - 1);
        }
        echo PHP_EOL; // Перевод на новую строку
    }
} else {
    echo "В английском алфавите всего 26 букв!";
}
?>
