import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Для ввода данных
        System.out.print("Введите n: ");
        int n = scanner.nextInt(); // Ввод данных
        if (n > 0 && n < 27) { // «Проверка на дурака»
            for (int i = 1; i <= n; i++) {
                char current = (char)('A' + n - 1); // Текущая буква
                for (int j = 0; j < i; j++) { // Количество повторений в строке
                    System.out.print(current); // Вывод
                    if (j != i - 1) {
                        System.out.print(" ");
                    }
                    current--;
                }
                System.out.println();
            }
        } else {
            System.out.println("В английском алфавите всего 26 букв!");
        }
    }
}
