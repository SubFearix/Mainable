package main

import (
    "fmt"
    "strconv"
    "bufio"
    "os"
    "strings"
)

func main() {
    fmt.Print("Введите числа через запятую и пробел: ")
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    input := scanner.Text()
    parts := strings.Split(input, " ") // Разбиваем строку
    for i, elem := range parts {
        sum := 0
        product := 1
        for _, ch := range elem {
            digit, _ := strconv.Atoi(string(ch)) // Строку в число
            sum += digit
            product *= digit
        }
        if sum < product {
            fmt.Print(i, " ")
        }
    }
}
