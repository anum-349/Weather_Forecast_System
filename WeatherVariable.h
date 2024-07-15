#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;
class WeatherVariable {
public:
    string type;
    double value;

    WeatherVariable(string ty, double va)
    {
        type = ty;
        value = va;
    }
};
class ManageWeatherVariable {
private:
    vector<WeatherVariable> variables;

public:
    void addVariable(const WeatherVariable& vari) {
        variables.push_back(vari);
    }

    void listVariables() {
        for (const auto& var : variables) {
            cout << "weather Variable Type: " << var.type << endl;
            cout<<"weather Variable Value: " << var.value << endl;
        }
    }
};
