puts "Введите n: "
n = gets.chomp.to_i # Ввод, удаление /n и в число
if n > 0 and n < 27 # «Проверка на дурака»
    (1..n).each do |i|
        current = 'A'.ord + n - 1 # Текущая буква (код символа)
        (0...i).each do |j| # Количество повторений в строке
            print current.chr
            if j != i - 1
                print " "
            end
            current -= 1
        end
        puts
    end
else
    puts "В английском алфавите всего 26 букв!"
end
