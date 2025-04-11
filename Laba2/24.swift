print("Введите количество чисел", terminator: " ")
if let input = readLine(), let n = Int(input) {
    if n > 0 {
        for i in 0..<n {
            if let numInput = readLine(), var num = Int(numInput) {
                num = abs(num)
                var summ = 0
                var mult = 1
                // Обрабатываем 0 отдельно
                if num == 0 {
                    summ = 0
                    mult = 0
                } else {
                    var tempNum = num
                    while tempNum > 0 {
                        let digit = tempNum % 10
                        summ += digit
                        mult *= digit
                        tempNum = tempNum / 10
                    }
                }
                // Сравниваем сумму и произведение
                if summ < mult {
                    print(i)
                }
            }
        }
    } else {
        print("Некорректное количество чисел")
    }
} else {
    print("Некорректное количество чисел")
}
