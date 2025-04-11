package main

import (
	"fmt"
	"strconv"
	"strings"
	"unicode"
	"bufio"
	"os"
)

type Warehouse struct {
	storageAreas      []rune
	shelvesPerZone    int
	sectionsPerShelf  int
	shelvesPerSection int
	cellCapacity      int
	storage           map[string]map[string]int
}

func NewWarehouse() *Warehouse {
	w := &Warehouse{
		storageAreas:      []rune{'A'},
		shelvesPerZone:    10,
		sectionsPerShelf:  7,
		shelvesPerSection: 4,
		cellCapacity:      10,
		storage:           make(map[string]map[string]int),
	}
	for _, zone := range w.storageAreas {
		for shelf := 1; shelf <= w.shelvesPerZone; shelf++ {
			for section := 1; section <= w.sectionsPerShelf; section++ {
				for shelfNum := 1; shelfNum <= w.shelvesPerSection; shelfNum++ {
					address := string(zone) + strconv.Itoa(shelf) + strconv.Itoa(section) + strconv.Itoa(shelfNum)
					w.storage[address] = make(map[string]int)
				}
			}
		}
	}
	return w
}

func (w *Warehouse) AddItem(itemName string, quantity int, address string) {
	address = strings.ToUpper(address)
	if _, exists := w.storage[address]; !exists {
		fmt.Printf("Ошибка: Ячейка %s не существует\n", address)
		return
	}
	currentItems := 0
	for _, qty := range w.storage[address] {
		currentItems += qty
	}
	if currentItems+quantity > w.cellCapacity {
		fmt.Printf("Ошибка: Превышена вместимость ячейки %s (макс. %d) сейчас %d\n",
			address, w.cellCapacity, currentItems)
		return
	}
	w.storage[address][itemName] += quantity
	fmt.Printf("Добавлено %d единиц товара '%s' в ячейку %s\nВ ячейке %s %d единиц товара\n",
		quantity, itemName, address, address, currentItems+quantity)
}

func (w *Warehouse) RemoveItem(itemName string, quantity int, address string) {
	address = strings.ToUpper(address)
	if _, exists := w.storage[address]; !exists {
		fmt.Printf("Ошибка: Ячейка %s не существует\n", address)
		return
	}
	if currentQty, exists := w.storage[address][itemName]; !exists || currentQty < quantity {
		fmt.Printf("Ошибка: Недостаточно товара '%s' в ячейке %s\n", itemName, address)
		return
	}
	w.storage[address][itemName] -= quantity
	if w.storage[address][itemName] == 0 {
		delete(w.storage[address], itemName)
	}
	fmt.Printf("Удалено %d единиц товара '%s' из ячейки %s\nВ ячейке %s осталось %d единиц товара '%s'\n",
		quantity, itemName, address, address, w.storage[address][itemName], itemName)
}

func (w *Warehouse) GetInfo() {
	totalCells := len(w.storage)
	usedCells := 0
	totalItems := 0
	for _, cell := range w.storage {
		if len(cell) > 0 {
			usedCells++
			for _, qty := range cell {
				totalItems += qty
			}
		}
	}
	totalCapacity := totalCells * w.cellCapacity
	warehouseLoad := float64(totalItems) * 100.0 / float64(totalCapacity)
	zoneItems := make(map[rune]int)
	zoneCapacity := make(map[rune]int)
	for _, zone := range w.storageAreas {
		zoneItems[zone] = 0
		zoneCapacity[zone] = 0
	}
	for addr, cell := range w.storage {
		zone := rune(addr[0])
		zoneCapacity[zone] += w.cellCapacity
		for _, qty := range cell {
			zoneItems[zone] += qty
		}
	}
	var nonEmptyCells []string
	var emptyCells []string
	for addr, cell := range w.storage {
		if len(cell) == 0 {
			emptyCells = append(emptyCells, addr)
		} else {
			nonEmptyCells = append(nonEmptyCells, addr)
		}
	}
	fmt.Println("\n=== ИНФОРМАЦИЯ О СКЛАДЕ ===")
	fmt.Printf("Общая загруженность склада: %.2f%%\n", warehouseLoad)
	fmt.Println("\nЗагруженность по зонам:")
	for _, zone := range w.storageAreas {
		zoneLoad := float64(zoneItems[zone]) * 100.0 / float64(zoneCapacity[zone])
		fmt.Printf("Зона %c: %.2f%% (%d/%d)\n",
			zone, zoneLoad, zoneItems[zone], zoneCapacity[zone])
	}
	fmt.Println("\nСодержимое непустых ячеек:")
	for _, addr := range nonEmptyCells {
		cell := w.storage[addr]
		fmt.Printf("%s: ", addr)
		first := true
		for item, qty := range cell {
			if !first {
				fmt.Print(", ")
			}
			fmt.Printf("%s: %d", item, qty)
			first = false
		}
		fmt.Println()
	}
	fmt.Println("\nПустые ячейки:")
	if len(emptyCells) == 0 {
		fmt.Println("Пустых ячеек нет")
	} else {
		fmt.Println(strings.Join(emptyCells, ", "))
	}
}

func splitCommand(command string) []string {
	var tokens []string
	var token strings.Builder
	inQuotes := false
	for _, ch := range command {
		if ch == '"' {
			inQuotes = !inQuotes
		} else if unicode.IsSpace(ch) && !inQuotes {
			if token.Len() > 0 {
				tokens = append(tokens, token.String())
				token.Reset()
			}
		} else {
			token.WriteRune(ch)
		}
	}
	if token.Len() > 0 {
		tokens = append(tokens, token.String())
	}
	return tokens
}

func main() {
	warehouse := NewWarehouse()
	fmt.Println("Система учета товаров на складе")
	fmt.Println("Доступные команды:")
	fmt.Println("ADD <наименование> <количество> <адрес> - добавить товар")
	fmt.Println("REMOVE <наименование> <количество> <адрес> - удалить товар")
	fmt.Println("INFO - информация о складе")
	fmt.Println("EXIT - выход")
	for {
		fmt.Print("\nВведите команду: ")
		var input string
		input, _ = bufio.NewReader(os.Stdin).ReadString('\n')
		command := splitCommand(input)
		if len(command) == 0 {
			continue
		}
		cmd := strings.ToUpper(command[0])
		switch cmd {
		case "EXIT":
			return
		case "ADD":
			if len(command) != 4 {
				fmt.Println("Ошибка: Неправильный формат команды ADD")
				continue
			}
			itemName := command[1]
			quantity, err := strconv.Atoi(command[2])
			if err != nil {
				fmt.Println("Ошибка: Количество должно быть числом")
				continue
			}
			address := command[3]
			warehouse.AddItem(itemName, quantity, address)
		case "REMOVE":
			if len(command) != 4 {
				fmt.Println("Ошибка: Неправильный формат команды REMOVE")
				continue
			}
			itemName := command[1]
			quantity, err := strconv.Atoi(command[2])
			if err != nil {
				fmt.Println("Ошибка: Количество должно быть числом")
				continue
			}
			address := command[3]
			warehouse.RemoveItem(itemName, quantity, address)
		case "INFO":
			warehouse.GetInfo()
		default:
			fmt.Println("Ошибка: Неизвестная команда")
		}
	}
}
