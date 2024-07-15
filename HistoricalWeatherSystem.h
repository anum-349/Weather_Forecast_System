#include <curl/curl.h>
#include<iostream>
#include <string>
#include <nlohmann/json.hpp> 
using json = nlohmann::json;
using namespace std; 
class HistoricalWeatherSystem {
private:
    string apiKey;
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
        ((string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }

public:
    HistoricalWeatherSystem(string key)
        {
            apiKey = key;
        }
        string fetchHistoricalData(double latitude, double longitude) {
        CURL* curl;
        CURLcode res;
        string readBuffer;

        curl = curl_easy_init();
        if (curl) {
            string url = "https://open-meteo.com/en/docs/historical-forecast-api?latitude=" + to_string(latitude) +
                "&longitude=" + to_string(longitude) + "&start_date=2023-01-01&end_date=2023-01-07";
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }
        return readBuffer;
    }

    void displayHistoricalData(const string& data) {
        auto jsonData = json::parse(data);
        cout << jsonData.dump(4) << endl;
    }
};
