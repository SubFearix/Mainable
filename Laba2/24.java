import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Введите числа через пробел:");
        String input = scanner.nextLine();
        String[] num = input.split(" "); // Разбиваем строку по пробелам
        for (int pos = 0; pos < num.length; pos++) {
            int numch = Integer.parseInt(num[pos]); // Переводим строку в число
            int n = Math.abs(numch), sum = 0, mult = 1;
            while (n > 0) {
                int digit = n % 10;
                sum += digit;
                mult *= digit;
                n /= 10;
            }
            if (sum < mult) {
                System.out.print(pos + " ");
            }
        }
    }
}
