import java.util.Scanner

fun main() {
    var count = 0
    val scanner = Scanner(System.`in`)
    print("Введите числа через пробел: ")
    val input = scanner.nextLine()
    val nums = input.split(" ") // Список разделенных элементов
    for (num in nums) {
        val numb = num.toInt() // Строку в число
        val st = Math.abs(numb).toString() // Число в строку
        if (st.length % 2 != 0) {
            count++
        }
    }
    println(count)
}
