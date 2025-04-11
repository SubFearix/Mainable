#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "Commands.h"
using namespace std;

enum class CommandType {
    CREATE_TRL,
    TRL_IN_STOP,
    STOPS_IN_TRL,
    TRLS,
    EXIT,
    UNKNOWN
};

CommandType parseCommand(const string& cmd) {
    if (cmd == "CREATE_TRL") return CommandType::CREATE_TRL;
    if (cmd == "TRL_IN_STOP") return CommandType::TRL_IN_STOP;
    if (cmd == "STOPS_IN_TRL") return CommandType::STOPS_IN_TRL;
    if (cmd == "TRLS") return CommandType::TRLS;
    if (cmd == "EXIT") return CommandType::EXIT;
    return CommandType::UNKNOWN;
}

int main() {
    TrolleySystem system;
    string command;
    cout << "Available commands:\n"
         << "CREATE_TRL [number] [stops...] - add new route\n"
         << "TRL_IN_STOP [stop] - trolleybuses in stop\n"
         << "STOPS_IN_TRL [number] - shows trolleybus route\n"
         << "TRLS - shows all routes\n"
         << "Enter command (EXIT ends programm):\n";
    while (getline(cin, command)) {
        size_t space_pos = command.find(' ');
        string cmd = (space_pos == string::npos) ? command : command.substr(0, space_pos);
        string args = (space_pos == string::npos) ? "" : command.substr(space_pos + 1);
        switch (parseCommand(cmd)) {
            case CommandType::CREATE_TRL: {
                size_t first_space = args.find(' ');
                if (first_space == string::npos) {
                    cout << "Invalid command format" << endl;
                    break;
                }
                string trl_name = args.substr(0, first_space);
                string stops_str = args.substr(first_space + 1);
                string stops_out = stops_str;
                vector<string> stops;
                size_t pos = 0;
                while ((pos = stops_str.find(' ')) != string::npos) {
                    stops.push_back(stops_str.substr(0, pos));
                    stops_str.erase(0, pos + 1);
                }
                stops.push_back(stops_str);
                system.createTrolley(trl_name, stops);
                break;
            }
            case CommandType::TRL_IN_STOP:
                system.printTrolleysInStop(args);
                break;
            case CommandType::STOPS_IN_TRL:
                system.printStopsForTrolley(args);
                break;
            case CommandType::TRLS:
                system.printAllTrolleys();
                break;
            case CommandType::EXIT:
                return 0;
            case CommandType::UNKNOWN:
                cout << "Unknown command" << endl;
                break;
        }
    }
    return 0;
}
