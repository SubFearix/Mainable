using System;
using System.Collections.Generic; // Для List

class Program {
    static void Main() {
        int count = 0;
        List<int> nums = new List<int>();
        Console.Write("Введите числа через пробел: ");
        string input = Console.ReadLine();
        string[] numbers = input.Split(new[] {' '});
        foreach (string numStr in numbers) {
            if (int.TryParse(numStr, out int num)) { // TryParse строку в число
                nums.Add(num);
            }
        }
        foreach (int num in nums) {
            string st = Math.Abs(num).ToString();
            if (st.Length % 2 != 0) {
                count++;
            }
        }
        Console.WriteLine(count);
    }
}
