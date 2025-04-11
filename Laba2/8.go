package main

import "fmt"

func main() {
    dict := map [int] string{
        1: "A", 2: "B", 3: "C", 4: "D", 5: "E", 6: "F", 7: "G", 8: "H", 9: "I", 10: "J",
        11: "K", 12: "L", 13: "M", 14: "N", 15: "O", 16: "P", 17: "Q", 18: "R", 19: "S", 20: "T", 21: "U", 22: "V", 23: "W", 24: "X", 25: "Y", 26: "Z",
    } // Словарь-алфавит
    var n int
    fmt.Scan(&n)
    if n > 0 && n < 27 { // «Проверка на дурака»
        kol := 1
        for i := n; i > 0; i-- {
            plus := n
            for j := 0; j < kol; j++ {
                print(dict[plus], " ")
                plus--
            }
            fmt.Println()
            kol++
        }
    } else {fmt.Println("Букв всего 26! Попробуйте снова")}
}
