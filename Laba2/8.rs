use std::io;

fn main() {
    println!("Введите n: ");
    let mut input = String::new(); // Изменяемая строка
    io::stdin().read_line(&mut input);
    let n: i32 = input.trim().parse().expect("Введите число"); // Trim обрезает пробелы, parse строку в число
    if n > 0 && n < 27 { // Проверка на дурака
        for i in 1..=n {
            let mut current = b'A' + (n - 1) as u8; // Текущая буква
            for j in 0..i {
                print!("{}", current as char);
                if j != i - 1 {
                    print!(" ");
                }
                current -= 1;
            }
            println!();
        }
    } else {
        println!("В английском алфавите всего 26 букв!");
    }
}
