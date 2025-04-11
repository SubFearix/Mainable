pos = 0
input = gets.chomp
num = input.split.map(&:to_i)
(num).each do |el|
    n = el.abs
    sum = 0
    mult = 1
    while n > 0
        digit = n % 10
        sum += digit
        mult *= digit
        n /= 10
    end
    if sum < mult
        print "#{pos} "
    end
    pos += 1
end
