#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <locale.h>
using namespace std;

class Warehouse {
private:
    vector<char> storage_areas = { 'A'};
    const int shelves_per_zone = 10;
    const int sections_per_shelf = 7;
    const int shelves_per_section = 4;
    const int cell_capacity = 10;
    map<string, map<string, int>> storage;

public:
    Warehouse() {
        for (char zone : storage_areas) {
            for (int shelf = 1; shelf <= shelves_per_zone; shelf++) {
                for (int section = 1; section <= sections_per_shelf; section++) {
                    for (int shelf_num = 1; shelf_num <= shelves_per_section; shelf_num++) {
                        string address = zone + to_string(shelf) + to_string(section) + to_string(shelf_num);
                        storage[address] = map<string, int>();
                    }
                }
            }
        }
    }

    void add_item(const string& item_name, int quantity, const string& address) {
        if (storage.find(address) == storage.end()) {
            cout << "Ошибка: Ячейка " << address << " не существует" << endl;
            return;
        }
        int current_items = 0;
        for (const auto& item : storage[address]) {
            current_items += item.second;
        }
        if (current_items + quantity > cell_capacity) {
            cout << "Ошибка: Превышена вместимость ячейки " << address
                 << " (макс. " << cell_capacity << ")" << " сейчас" << " " << current_items << endl;
            return;
        }
        storage[address][item_name] += quantity;
        cout << "Добавлено " << quantity << " единиц товара '" << item_name
             << "' в ячейку " << address << endl << "В ячейке " << address << " " << current_items + quantity << " единиц товара" << endl;
    }

    void remove_item(const string& item_name, int quantity, const string& address) {
        if (storage.find(address) == storage.end()) {
            cout << "Ошибка: Ячейка " << address << " не существует" << endl;
            return;
        }
        if (storage[address].find(item_name) == storage[address].end() ||
            storage[address][item_name] < quantity) {
            cout << "Ошибка: Недостаточно товара " << item_name
                 << "' в ячейке " << address << endl;
            return;
        }
        storage[address][item_name] -= quantity;
        if (storage[address][item_name] == 0) {
            storage[address].erase(item_name);
        }
        cout << "Удалено " << quantity << " единиц товара " << item_name
             << " из ячейки " << address << endl << "В ячейке " << address << " осталось " << storage[address][item_name] << " единиц товара " << item_name << endl;
    }

    void get_info() {
        int total_cells = storage.size();
        int used_cells = 0;
        int total_items = 0;
        for (const auto& cell : storage) {
            if (!cell.second.empty()) {
                used_cells++;
                for (const auto& item : cell.second) {
                    total_items += item.second;
                }
            }
        }
        int total_capacity = total_cells * cell_capacity;
        double warehouse_load = (total_items * 100.0) / total_capacity;
        map<char, int> zone_items;
        map<char, int> zone_capacity;
        for (char zone : storage_areas) {
            zone_items[zone] = 0;
            zone_capacity[zone] = 0;
        }
        for (const auto& cell : storage) {
            char zone = cell.first[0];
            zone_capacity[zone] += cell_capacity;
            for (const auto& item : cell.second) {
                zone_items[zone] += item.second;
            }
        }
        vector<pair<string, map<string, int>>> non_empty_cells;
        vector<string> empty_cells;
        for (const auto& cell : storage) {
            if (cell.second.empty()) {
                empty_cells.push_back(cell.first);
            }
            else {
                non_empty_cells.push_back(cell);
            }
        }
        cout << "\n=== ИНФОРМАЦИЯ О СКЛАДЕ ===" << endl;
        cout << "Общая загруженность склада: " << fixed << setprecision(2)
             << warehouse_load << "%" << endl;
        cout << "\nЗагруженность по зонам:" << endl;
        for (char zone : storage_areas) {
            double zone_load = (zone_items[zone] * 100.0) / zone_capacity[zone];
            cout << "Зона " << zone << ": " << fixed << setprecision(2)
                 << zone_load << "% (" << zone_items[zone] << "/"
                 << zone_capacity[zone] << ")" << endl;
        }
        cout << "\nСодержимое непустых ячеек:" << endl;
        for (const auto& cell : non_empty_cells) {
            cout << cell.first << ": ";
            bool first = true;
            for (const auto& item : cell.second) {
                if (!first) cout << ", ";
                cout << item.first << ": " << item.second;
                first = false;
            }
            cout << endl;
        }
        cout << "\nПустые ячейки:" << endl;
        if (empty_cells.empty()) {
            cout << "Пустых ячеек нет" << endl;
        }
        else {
            for (size_t i = 0; i < empty_cells.size(); i++) {
                if (i != 0) cout << ", ";
                cout << empty_cells[i];
            }
            cout << endl;
        }
    }
};

vector<string> split_command(const string& command) {
    vector<string> tokens;
    string token;
    bool in_quotes = false;
    for (char ch : command) {
        if (ch == '\"') {
            in_quotes = !in_quotes;
        }
        else if (isspace(ch) && !in_quotes) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        }
        else {
            token += ch;
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Warehouse warehouse;
    cout << "Система учета товаров на складе" << endl;
    cout << "Доступные команды:" << endl;
    cout << "ADD <наименование> <количество> <адрес> - добавить товар" << endl;
    cout << "REMOVE <наименование> <количество> <адрес> - удалить товар" << endl;
    cout << "INFO - информация о складе" << endl;
    cout << "EXIT - выход" << endl;

    while (true) {
        cout << "\nВведите команду: ";
        string input;
        getline(cin, input);
        vector<string> command = split_command(input);
        if (command.empty()) continue;
        string cmd = command[0];
        transform(cmd.begin(), cmd.end(), cmd.begin(), ::toupper);
        if (cmd == "EXIT") {
            break;
        }
        else if (cmd == "ADD") {
            if (command.size() != 4) {
                cout << "Ошибка: Неправильный формат команды ADD" << endl;
                continue;
            }
            try {
                string item_name = command[1];
                int quantity = stoi(command[2]);
                string address = command[3];
                transform(address.begin(), address.end(), address.begin(), ::toupper);
                warehouse.add_item(item_name, quantity, address);
            }
            catch (const invalid_argument&) {
                cout << "Ошибка: Количество должно быть числом" << endl;
            }
        }
        else if (cmd == "REMOVE") {
            if (command.size() != 4) {
                cout << "Ошибка: Неправильный формат команды REMOVE" << endl;
                continue;
            }
            try {
                string item_name = command[1];
                int quantity = stoi(command[2]);
                string address = command[3];
                transform(address.begin(), address.end(), address.begin(), ::toupper);
                warehouse.remove_item(item_name, quantity, address);
            }
            catch (const invalid_argument&) {
                cout << "Ошибка: Количество должно быть числом" << endl;
            }
        }
        else if (cmd == "INFO") {
            warehouse.get_info();
        }
        else {
            cout << "Ошибка: Неизвестная команда" << endl;
        }
    }
    return 0;
}
