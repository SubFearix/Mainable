const input: string = prompt("Введите числа через пробел:");
const nums: number[] = input.trim().split(" ").map(Number);
let count: number = 0;
for (const num of nums) {
    const str: string = Math.abs(num).toString();
    if (str.length % 2 !== 0) {
        count++;
    }
}
console.log(count);
