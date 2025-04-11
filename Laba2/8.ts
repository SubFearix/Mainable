const nStr = prompt('Введите n: '); // Ввод
const n = parseInt(nStr || '0'); // Строка в число
if (n > 0 && n < 27) {
    for (let i = 1; i <= n; i++) {
        let current = 'A'.charCodeAt(0) + n - 1; // Буква
        let line = ''; 
        for (let j = 0; j < i; j++) {
            line += String.fromCharCode(current);
            if (j !== i - 1) {
                line += ' ';
            }
            current--;
        }
        console.log(line);
    }
} else {
    console.log('В английском алфавите всего 26 букв!');
}
