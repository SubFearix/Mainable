nums = input("Введите числа через запятую и пробел").split(", ")
out = 0
for i in nums:
    if len(str(abs(int(i)))) % 2 != 0: # Проверяем длину числа, преобразованного в строку
        out += 1
print(out)
