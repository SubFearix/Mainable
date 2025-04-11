#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int count = 0;
    vector <int> nums;
    string input;
    cout << "Введите числа через пробел: ";
    getline(cin, input); // Считываем всю строку
    stringstream ss(input); // Разбиваем строку на числа
    int num;
    while (ss >> num) { // Читаем числа из строки
        nums.push_back(num);
    }
    for (int num : nums) {
        string st = to_string(abs(num)); // Преобразовываем число в строку
        if (st.length() % 2 != 0) { // Считаем длину строки
            count++;
        }
    }
    cout << count;
}
