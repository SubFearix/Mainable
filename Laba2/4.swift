let nums = readLine()?.components(separatedBy: ", ") ?? []
var out = 0
for i in nums {
    if let number = Int(i) {
        let length = String(abs(number)).count
        if length % 2 != 0 {
            out += 1
        }
    }
}
print(out)
