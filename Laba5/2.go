package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Visitor struct {
	ticketNumber int
	duration     int
}

func main() {
	fmt.Print("Введите количество окон: ")
	reader := bufio.NewReader(os.Stdin)
	windowsCount := 0
	for {
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		num, err := strconv.Atoi(input)
		if err != nil || num < 1 {
			fmt.Println("Количество окон должно быть положительным числом. Попробуйте снова!")
			fmt.Print("Введите количество окон: ")
			continue
		}
		windowsCount = num
		break
	}
	visitors := []Visitor{}
	ticket := 1
	fmt.Println("Вводите команды (ENQUEUE <длительность> или DISTRIBUTE):")
	for {
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		parts := strings.Fields(input)
		if len(parts) == 0 {
			continue
		}
		command := parts[0]
		if command == "ENQUEUE" {
			if len(parts) < 2 {
				fmt.Println("Не указана длительность. Попробуйте снова!")
				continue
			}
			duration, err := strconv.Atoi(parts[1])
			if err != nil || duration < 1 {
				fmt.Println("Продолжительность не может быть меньше 1. Попробуйте снова!")
				continue
			}
			fmt.Printf("Талон №%d\n", ticket)
			visitors = append(visitors, Visitor{ticket, duration})
			ticket++
		} else if command == "DISTRIBUTE" {
			if len(visitors) == 0 {
				fmt.Println("Очередь пуста!")
				return
			}
			break
		} else {
			fmt.Println("Некорректная команда. Попробуйте снова!")
		}
	}
	windowsTime := make([]int, windowsCount)
	windowsVisitors := make([][]Visitor, windowsCount)
	for _, visitor := range visitors {
		minWindow := 0
		for i := 1; i < windowsCount; i++ {
			if windowsTime[i] < windowsTime[minWindow] {
				minWindow = i
			}
		}
		windowsTime[minWindow] += visitor.duration
		windowsVisitors[minWindow] = append(windowsVisitors[minWindow], visitor)
	}
	fmt.Println("\nОптимальное распределение:")
	for i := 0; i < windowsCount; i++ {
		fmt.Printf("Окно %d (%d минут): ", i+1, windowsTime[i])
		for j, visitor := range windowsVisitors[i] {
			fmt.Printf("№%d", visitor.ticketNumber)
			if j != len(windowsVisitors[i])-1 {
				fmt.Print(" - ")
			}
		}
		fmt.Println()
	}
}
