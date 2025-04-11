#include <iostream>
using namespace std;

int main() {
    int num, pos = 0;
    while (cin >> num) { // Ввод
        int n = abs(num), sum = 0, mult = 1;
        while (n > 0) {
            int digit = n % 10;
            sum += digit; // Считаем сумму цифр
            mult *= digit; // Считаем произведение цифр
            n /= 10;
        }
        if (sum < mult) {
            cout << pos << " ";
        }
        pos++;
    }
    return 0;
}
