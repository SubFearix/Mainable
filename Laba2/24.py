n = int(input("Введите количество чисел "))
if n > 0:
    for i in range(n):
        num = abs(int(input()))
        summ = 0
        mult = 1
        # Обрабатываем 0 отдельно
        if num == 0:
            summ = 0
            mult = 0
        else:
            while num > 0:
                digit = num % 10
                summ += digit
                mult *= digit
                num = num // 10
        # Сравниваем сумму и произведение
        if summ < mult:
            print(i, end="\n")
else:
    print("Некорректное количество чисел")
