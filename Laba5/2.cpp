#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <locale.h>
using namespace std;

struct Visitor {
    int ticketNumber;
    int duration;
};

bool compareByDuration(const Visitor& a, const Visitor& b) {
    return a.duration > b.duration;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int windowsCount;
    cout << "Введите количество окон: ";
    cin >> windowsCount;
    while (windowsCount < 1) {
        cout << "Количество окон должно быть положительным числом. Попробуйте снова!" << endl;
        cin >> windowsCount;
    }
    vector<Visitor> visitors;
    int ticket = 1;
    string command;
    cout << "Вводите команды (ENQUEUE <длительность> или DISTRIBUTE):" << endl;
    while (true) {
        cin >> command;
        if (command == "ENQUEUE") {
            int duration;
            cin >> duration;
            if (duration > 0) {
                cout << "Талон №" << ticket << endl;
                visitors.push_back({ ticket, duration });
                ticket++;
            }
            else {
                cout << "Продолжительность не может быть меньше 1. Попробуйте снова!" << endl;
            }
        }
        else if (command == "DISTRIBUTE") {
            if (visitors.empty()) {
                cout << "Очередь пуста!" << endl;
                return 0;
            }
            break;
        }
        else {
            cout << "Некорректная команда. Попробуйте снова!" << endl;
        }
    }
    sort(visitors.begin(), visitors.end(), compareByDuration);
    vector<int> windowsTime(windowsCount, 0);
    vector<vector<Visitor>> windowsVisitors(windowsCount);
    for (const auto& visitor : visitors) {
        int minWindow = 0;
        for (int i = 1; i < windowsCount; i++) {
            if (windowsTime[i] < windowsTime[minWindow]) {
                minWindow = i;
            }
        }
        windowsTime[minWindow] += visitor.duration;
        windowsVisitors[minWindow].push_back(visitor);
    }
    for (auto& window : windowsVisitors) {
        sort(window.begin(), window.end(), [](const Visitor& a, const Visitor& b) {
            return a.ticketNumber < b.ticketNumber;
        });
    }
    cout << "\nОптимальное распределение:" << endl;
    for (int i = 1; i <= windowsCount; i++) {
        cout << "Окно " << i << " (" << windowsTime[i-1] << " минут): ";
        for (size_t j = 0; j < windowsVisitors[i-1].size(); j++) {
            cout << "№" << windowsVisitors[i-1][j].ticketNumber;
            if (j != windowsVisitors[i-1].size() - 1) cout << " - ";
        }
        cout << endl;
    }
    return 0;
}
