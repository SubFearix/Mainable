import java.util.Scanner

fun main() {
    val scanner = Scanner(System.`in`)
    println("Введите числа через пробел:")
    val input = scanner.nextLine()
    val num = input.split(" ").toTypedArray() // Разбиваем строку по пробелам
    for (pos in num.indices) {
        val numch = num[pos].toInt() // Переводим строку в число
        var n = Math.abs(numch)
        var sum = 0
        var mult = 1
        while (n > 0) {
            val digit = n % 10
            sum += digit
            mult *= digit
            n /= 10
        }
        if (sum < mult) {
            print("$pos ")
        }
    }
}
