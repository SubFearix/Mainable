use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input);
    let mut pos = 0;
    for num_str in input.split_whitespace() {
        let num: i32 = num_str.parse().unwrap();
        let n = num.abs();
        let mut sum = 0;
        let mut mult = 1;
        let mut temp = n;
        while temp > 0 {
            let digit = temp % 10;
            sum += digit;
            mult *= digit;
            temp /= 10;
        }
        if sum < mult {
            print!("{} ", pos);
        }
        pos += 1;
    }
}
