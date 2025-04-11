using System;

class Program {
    static void Main() {
        Console.WriteLine("Введите числа через пробел:");
        string input = Console.ReadLine();
        string[] num = input.Split(new[] { ' ' }); // Разбиваем строку по пробелам
        for (int pos = 0; pos < num.Length; pos++) {
            int.TryParse(num[pos], out int numch); // Переводим строку в число
            int n = Math.Abs(numch), sum = 0, mult = 1;
            while (n > 0) {
                int digit = n % 10;
                sum += digit;
                mult *= digit;
                n /= 10;
            }
            if (sum < mult) {
                Console.Write(pos + " ");
            }
        }
    }
}
