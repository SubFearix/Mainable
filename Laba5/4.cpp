#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

class StudentQueue {
private:
    vector<int> students;
    vector<int> suspiciousList;
    vector<int> immortalList;
public:
    void newStudents(int number) {
        if (number > 0) {
            int start = students.empty() ? 1 : students.back() + 1;
            for (int i = start; i < start + number; i++) {
                students.push_back(i);
            }
            cout << "Welcome " << number << " clever students!" << endl;
        }
        else if (number < 0) {
            int removeCount = -number;
            if (removeCount > students.size()) {
                cerr << "Incorrect" << endl;
                return;
            }
            vector<int> toRemove;
            for (auto it = suspiciousList.begin(); it != suspiciousList.end() && toRemove.size() < removeCount; ) {
                int student = *it;
                if (find(immortalList.begin(), immortalList.end(), student) == immortalList.end()) {
                    toRemove.push_back(student);
                    it = suspiciousList.erase(it);
                }
                else {
                    ++it;
                }
            }
            for (auto it = students.rbegin(); it != students.rend() && toRemove.size() < removeCount; ++it) {
                int student = *it;
                if (find(immortalList.begin(), immortalList.end(), student) == immortalList.end() &&
                    find(toRemove.begin(), toRemove.end(), student) == toRemove.end()) {
                    toRemove.push_back(student);
                }
            }
            if (toRemove.size() < removeCount) {
                cerr << "Incorrect" << endl;
                return;
            }
            for (int student : toRemove) {
                students.erase(find(students.begin(), students.end(), student));
            }
            cout << "GoodBye " << toRemove.size() << " clever students!" << endl;
        }
    }
    void suspicious(int numberStudent) {
        if (numberStudent <= 0 || (students.empty() ? true : numberStudent > students.back())) {
            cerr << "Incorrect" << endl;
            return;
        }
        if (find(students.begin(), students.end(), numberStudent) == students.end()) {
            cerr << "Incorrect" << endl;
            return;
        }
        if (find(immortalList.begin(), immortalList.end(), numberStudent) != immortalList.end()) {
            return;
        }
        if (find(suspiciousList.begin(), suspiciousList.end(), numberStudent) == suspiciousList.end()) {
            suspiciousList.push_back(numberStudent);
            cout << "The suspected student " << numberStudent << endl;
        }
    }
    void immortal(int numberStudent) {
        if (numberStudent <= 0 || (students.empty() ? true : numberStudent > students.back())) {
            cerr << "Incorrect" << endl;
            return;
        }
        if (find(students.begin(), students.end(), numberStudent) == students.end()) {
            cerr << "Incorrect" << endl;
            return;
        }
        if (find(immortalList.begin(), immortalList.end(), numberStudent) == immortalList.end()) {
            immortalList.push_back(numberStudent);
            auto it = find(suspiciousList.begin(), suspiciousList.end(), numberStudent);
            if (it != suspiciousList.end()) {
                suspiciousList.erase(it);
            }
            cout << "Student " << numberStudent << " is immortal!" << endl;
        }
    }
    void topList() {
        sort(suspiciousList.begin(), suspiciousList.end());
        cout << "List of students for expulsion: ";
        if (suspiciousList.empty()) {
            cout << "Empty";
        }
        else {
            for (size_t i = 0; i < suspiciousList.size(); ++i) {
                if (i != 0) cout << ", ";
                cout << "Student " << suspiciousList[i];
            }
        }
        cout << endl;
    }
    void scount() {
        cout << "List of students for expulsion consists of " << suspiciousList.size() << " students" << endl;
    }
};

int main() {
    StudentQueue queue;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        string command;
        iss >> command;
        if (command == "NEW_STUDENTS") {
            int number;
            iss >> number;
            queue.newStudents(number);
        }
        else if (command == "SUSPICIOUS") {
            int number;
            iss >> number;
            queue.suspicious(number);
        }
        else if (command == "IMMORTAL") {
            int number;
            iss >> number;
            queue.immortal(number);
        }
        else if (command == "TOP-LIST") {
            queue.topList();
        }
        else if (command == "SCOUNT") {
            queue.scount();
        }
        else if (command == "EXIT") {
            return 0;
        }
        else {
            cerr << "Incorrect" << endl;
        }
    }
    return 0;
}
