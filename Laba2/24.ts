let input = prompt("Введите числа через пробел:");
const numbers = input.trim().split(" ").map(Number); // Разбиваем строку на числа
let pos = 0;
let result: number[] = []; // Массив для хранения позиций
for (const num of numbers) {
    const n = Math.abs(num);
    let sum = 0;
    let mult = 1;
    let temp = n;
    while (temp > 0) {
        const digit = temp % 10;
        sum += digit;
        mult *= digit;
        temp = Math.floor(temp / 10); // Округление вниз
    }
    if (sum < mult) {
        result.push(pos); // Сохраняем позицию, если условие выполнено
    }
    pos++;
}
console.log(result.join(' '));
