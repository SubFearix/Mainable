puts "Введите числа через пробел: "
input = gets.chomp
nums = input.split.map(&:to_i)
count = nums.count { |num| num.abs.to_s.length.odd? }
puts count
