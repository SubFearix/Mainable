use std::io;

fn main() {
    println!("Введите числа через пробел: ");
    let mut input = String::new();
    io::stdin().read_line(&mut input);
    let nums: Vec<i32> = input.split_whitespace().filter_map(|s| s.parse().ok()).collect(); // Как map в питоне, собирает в вектор
    let mut count = 0;
    for &num in &nums {
        let num_str = num.abs().to_string();
        if num_str.len() % 2 != 0 {
            count += 1;
        }
    }
    println!("{}", count);
}
