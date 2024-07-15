#include <iostream>
#include <string>
#include<fstream>
using namespace std; 
class OfflineMode {
public:
    static void saveToLocal(const string& data, const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << data;
            file.close();
        }
    }

    static string loadFromLocal(const string& filename) {
        ifstream file(filename);
        string data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
        return data;
    }
};
