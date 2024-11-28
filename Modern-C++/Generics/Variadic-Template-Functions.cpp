#include <iostream>
#include <functional> // for std::reference_wrapper

// Step 1: Define the Sensor class
class Sensor 
{
private:
    float reading;

public:
    // Constructor to initialize the sensor reading
    Sensor(float value) : reading(value) {}

    // Method to get the sensor's reading
    float getReading() const {
        return reading;
    }
};

// Variadic template function to sum sensor readings using fold expression
template<typename... Sensors>
float sumSensorReadings(Sensors... sensors) 
{
    // Fold expression to sum the readings of the sensors
    return (sensors.get().getReading() + ...);
}

int main() 
{
    Sensor tempSensor(25.5);    // Temperature sensor reading 25.5
    Sensor humiditySensor(60.2); // Humidity sensor reading 60.2
    Sensor pressureSensor(1013.8); // Pressure sensor reading 1013.8

    // Sum the sensor readings using sumSensorReadings
    float totalSum = sumSensorReadings(std::ref(tempSensor), std::ref(humiditySensor), std::ref(pressureSensor));

    // Output the result
    std::cout << "Total sum of sensor readings: " << totalSum << std::endl;

    return 0;
}
