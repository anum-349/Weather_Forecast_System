#include <iostream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp> 
using json = nlohmann::json;
using namespace std;
class Location {
public:
    string name;
    double latitude;
    double longitude;
    Location(string na, double la , double lo )
    {
        name=na;
        latitude=la;
        longitude=lo;
    }
};

class ManageLocation {
private:
    vector<Location> locations;

public:
    void addLocation(const Location& location) {
        locations.push_back(location);
    }

    void removeLocation(const string& name) {
        locations.erase(
            remove_if(locations.begin(), locations.end(), [&](const Location& loc) { return loc.name == name; }),
            locations.end());
    }

    void listLocations() {
        for (const auto& loc : locations) {
            cout << "Location Name: " << loc.name << endl;
            cout << "Latitude: " << loc.latitude << endl;
            cout<<"Longitude: " << loc.longitude << endl;
        }
    }
};