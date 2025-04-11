const input = prompt("Введите числа через пробел:");
const numbers = input.trim().split(" ").map(Number);
let result = [];
for (let i = 0; i < numbers.length; i++) {
    const num = numbers[i];
    const n = Math.abs(num);
    let sum = 0, mult = 1;
    let temp = n;
    while (temp > 0) {
        const digit = temp % 10;
        sum += digit;
        mult *= digit;
        temp = Math.floor(temp / 10);
    }
    if (sum < mult) {
        result.push(i);
    }
}
console.log(result.join(" "));
