let count = 0;
const input = prompt("Введите числа через пробел:");
const nums = input.trim().split(" ").map(Number);  
for (const num of nums) {
    const str = Math.abs(num).toString();
    if (str.length % 2 !== 0) {
        count++;
    }
}
console.log(count);
