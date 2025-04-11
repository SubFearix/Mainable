import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int count = 0;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Введите числа через пробел: ");
        String input = scanner.nextLine();
        String[] nums = input.split(" "); // Список разделенных элементов
        for (String num : nums) {
            int numb = Integer.parseInt(num); // Строку в число
            String st = Integer.toString(Math.abs(numb)); // Число в строку
            if (st.length() % 2 != 0) {
                count++;
            }
        }
        System.out.println(count);
    }
}
