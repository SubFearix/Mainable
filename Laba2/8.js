const n = parseInt(prompt("Введите n: "));
if (n > 0 && n < 27) { // «Проверка на дурака»
    for (let i = 1; i <= n; i++) {
        let current = 'A'.charCodeAt(0) + n - 1; // Код текущей буквы
        let line = "";
        for (let j = 0; j < i; j++) { // Количество повторений в строке
            line += String.fromCharCode(current);
            if (j !== i - 1) {
                line += " ";
            }
            current--;
        }
        console.log(line);
    }
} else {
    console.log("В английском алфавите всего 26 букв!");
}
