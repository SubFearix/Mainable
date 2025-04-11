package main

import (
    "fmt"
    "math"
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
    parts := strings.Split(input, ", ") // Разбиваем строку
    out := 0
    for _, elem := range parts {
        two, _ := strconv.ParseFloat(elem, 64) // Переводим строку в float64 для взятия модуля
        if len(strconv.Itoa(int(math.Abs(two))))%2 != 0 { // Itoa для перевода числа в строку
            out++
        }
    }
    fmt.Println(out)
}
