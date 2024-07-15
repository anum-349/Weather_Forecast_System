#include <iostream>
#include <string>
#include<fstream>
#include <nlohmann/json.hpp> 
using json = nlohmann::json;
using namespace std; 
class DataExport {
public:
    static void exportToCSV(const string& data, const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            auto jsonData = json::parse(data);
            for (auto& el : jsonData.items()) {
                file << el.key() << " , ";
            }
            file << endl;
            for (auto& el : jsonData.items()) {
                file << el.value() << " , ";
            }
            file << endl;
            file.close();
        }
    }

    static void exportToJSON(const string& data, const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << data;
            file.close();
        }
    }
};
