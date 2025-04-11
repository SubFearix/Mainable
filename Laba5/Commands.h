#ifndef COMMANDS_H
#define COMMANDS_H
#include <string>
#include <vector>
#include <map>
class TrolleySystem {
private:
    std::map<std::string, std::vector<std::string>> trolleys;
    std::map<std::string, std::vector<std::string>> stops;
public:
    void createTrolley(const std::string& name, const std::vector<std::string>& stops);
    void printTrolleysInStop(const std::string& stop) const;
    void printStopsForTrolley(const std::string& trolley) const;
    void printAllTrolleys() const;
};
#endif // COMMANDS_H
