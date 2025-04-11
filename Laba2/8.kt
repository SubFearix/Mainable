import java.util.Scanner

fun main() {
    val scanner = Scanner(System.`in`) // Для ввода данных
    print("Введите n: ")
    val n = scanner.nextInt() // Ввод данных
    if (n > 0 && n < 27) { // «Проверка на дурака»
        for (i in 1..n) {
            var current = 'A' + (n - 1) // Текущая буква
            repeat(i) { j ->
                print(current) // Вывод
                if (j != i - 1) {
                    print(" ")
                }
                current--
            }
            println()
        }
    } else {
        println("В английском алфавите всего 26 букв!")
    }
}
