#include <iostream>
#include <vector>

using namespace std;

// Templated DataLogger class
template <typename T>
class DataLogger
{
    private:

    vector<T> logs;  // To store logged sensor data
    
    public:

    // Method to log sensor data
    void logData(const T& data) 
    {
        logs.push_back(data);
    }

    // Method to display logged data
    void displayLogs()
    {
        for (const auto& data : logs) 
        {
            cout << data << endl;
        }
    }
};

// Alias templates for specific sensor loggers
using TemperatureLogger = DataLogger<double>;
using PressureLogger = DataLogger<int>;
using SpeedLogger = DataLogger<float>;

int main() 
{

    // Log temperature data (as double)

    TemperatureLogger tempLogger;    // DataLogger<double> tempLogger;
    tempLogger.logData(36.5);
    tempLogger.logData(37.1);

    // Log pressure data (as int)

    PressureLogger pressureLogger;   // DataLogger<int> pressureLogger;
    pressureLogger.logData(1012);
    pressureLogger.logData(1008);

    // Log speed data (as float)

    SpeedLogger speedLogger;        // DataLogger<float> speedLogger;
    speedLogger.logData(45.6f);
    speedLogger.logData(50.2f);

    // Display the logged data
    cout << "Temperature Logs:\n";
    tempLogger.displayLogs();

    cout << "\nPressure Logs:\n";
    pressureLogger.displayLogs();

    cout << "\nSpeed Logs:\n";
    speedLogger.displayLogs();

    return 0;
}