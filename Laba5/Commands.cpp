#include "Commands.h"
#include <iostream>
#include <algorithm>
using namespace std;

void TrolleySystem::createTrolley(const string& name, const vector<string>& stop_list) {
    if (stop_list.size() < 2) {
        cout << "Trolleybus must have at least 2 stops" << endl;
        return;
    }
    vector<string> unique_stops = stop_list;
    sort(unique_stops.begin(), unique_stops.end());
    auto last = unique(unique_stops.begin(), unique_stops.end());
    unique_stops.erase(last, unique_stops.end());
    if (unique_stops.size() != stop_list.size()) {
        cout << "Trolleybus route contains duplicate stops" << endl;
        return;
    }
    trolleys[name] = stop_list;
    for (const auto& stop : stop_list) {
        stops[stop].push_back(name);
    }
    cout << "Successfully added new trolleybus " << name << endl;
}

void TrolleySystem::printTrolleysInStop(const string& stop) const {
    auto it = stops.find(stop);
    if (it == stops.end()) {
        cout << "No trolleys for stop " << stop << endl;
        return;
    }
    cout << "Trolleys for stop " << stop << ": ";
    for (const auto& trolley : it->second) {
        cout << trolley << " ";
    }
    cout << endl;
}

void TrolleySystem::printStopsForTrolley(const string& trolley) const {
    auto it = trolleys.find(trolley);
    if (it == trolleys.end()) {
        cout << "No stops for trolley " << trolley << endl;
        return;
    }
    cout << "Stops for trolley " << trolley << ":" << endl;
    for (const auto& stop : it->second) {
        cout << stop << " (other trolleys: ";
        for (const auto& other_trolley : stops.at(stop)) {
            if (other_trolley != trolley) {
                cout << other_trolley << " ";
            }
        }
        cout << ")" << endl;
    }
}

void TrolleySystem::printAllTrolleys() const {
    if (trolleys.empty()) {
        cout << "No trolleys in system" << endl;
        return;
    }
    cout << "All trolleys:" << endl;
    for (const auto& pair : trolleys) {
        cout << pair.first << ": ";
        for (const auto& stop : pair.second) {
            cout << stop << " ";
        }
        cout << endl;
    }
}
