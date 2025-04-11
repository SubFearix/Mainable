#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите n: ";
    cin >> n;
    if (n > 0 and n < 27){ // «Проверка на дурака»
        for (int i = 1; i <= n; i++) {
            char current = 'A' + n - 1; // Текущая буква
            for (int j = 0; j < i; j++) { // Количество повторений в строке
                cout << current;
                if (j != i - 1) {
                    cout << " ";
                }
                current--;
            }
            cout << endl;
        }
    } else cout << "В английском алфавите всего 26 букв!";
    return 0;
}
