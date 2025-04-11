using System;

class Program {
    static void Main() {
        Console.Write("Введите число N: ");
        int N = int.Parse(Console.ReadLine()); // Чтение числа N
        if (N > 0 && N < 27) // «Проверка на дурака»
        {
            for (int i = 1; i <= N; i++) {
                char letter = (char)('A' + N-1); // Получаем букву
                for (int j = 0; j < i; j++) {
                    Console.Write(letter);
                    if (j != i - 1) // Добавляем пробел, если это не последний символ в строке
                    {
                        Console.Write(" ");
                    }
                    letter--;
                }
                Console.WriteLine(); // Переход на новую строку
            }
        } else {
            Console.Write("Букв всего 26! Попробуйте снова");
        }
    }
}
