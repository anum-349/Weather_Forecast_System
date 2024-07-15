#include <iostream>
#include"Location.h"
#include"WeatherForecastingSystem.h"
#include"HistoricalWeatherSystem.h"
#include"AirQualityForecastingSystem.h"
#include"DataExport.h"
#include"OfflineMode.h"
using namespace std;
int main() {
    ManageLocation locManager;
    string key,loc;
    cout << "Enter Open Meteo Key: ";
    getline(cin, key);
    WeatherForecastingSystem weatherSystem(key);
    HistoricalWeatherSystem historicalSystem(key);
    AirQualityForecastingSystem airQualitySystem(key);
    locManager.addLocation(Location("Rawalpindi", 40.7128, -74.0060));
    string weatherData = weatherSystem.fetchWeatherData(40.7128, -74.0060);
    int choice;
    do {
        cout << "1: Add Location. " << endl;
        cout << "2: Remove Location. " << endl;
        cout << "3: List Of Location. " << endl;
        cout << "4: Display Weather Forecast. " << endl;
        cout << "5: Display AirQuality Forecast. " << endl;
        cout << "6: Display Historical Forecast. " << endl;
        cout << "7: Export to csv. " << endl;
        cout << "8: export to json. " << endl;
        cout << "9: OfflineData. " << endl;
        cout << "10: Exit. " << endl;
        cout << "Choose a No: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter Location/city Name: ";
            getline(cin, loc);
            locManager.addLocation(Location(loc, 40.7128, -74.0060));
        }
        else if (choice == 2)
        {
            cout << "Enter Location/city Name: ";
            getline(cin, loc);
            locManager.removeLocation(loc);
        }
        else if (choice == 3)
        {
            locManager.listLocations();
        }
        else if (choice == 4)
        {
            weatherSystem.displayWeatherData(weatherData);
        }
        else if (choice == 5)
        {
            string airQualityData = airQualitySystem.fetchAirQualityData(40.7128, -74.0060);
            airQualitySystem.displayAirQualityData(airQualityData);
        }
        else if (choice == 6)
        {
            string historicalData = historicalSystem.fetchHistoricalData(40.7128, -74.0060);
            historicalSystem.displayHistoricalData(historicalData);
        }
        else if (choice == 7)
        {

            DataExport::exportToCSV(weatherData, "WeatherForecast.csv");
        }
        else if (choice == 7)
        {

            DataExport::exportToJSON(weatherData, "WeatherForecast.json");
        }
        else if (choice == 9)
        {
            string offlineData = OfflineMode::loadFromLocal("WeatherForecast_offline.json");
            cout << "Offline Data: " << offlineData << endl;
            OfflineMode::saveToLocal(weatherData, "WeatherForecast.json");
        }
        else
            cout << "You Enter Invalid No." << endl;
    } while (!cin.fail() && choice != 10);
    return 0;
}
