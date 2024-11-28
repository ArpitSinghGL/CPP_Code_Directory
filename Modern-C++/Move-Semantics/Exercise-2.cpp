#include <iostream>
#include <vector>
#include <utility> // for std::move

class SensorData {
private:
    std::vector<int> readings;  // stores the sensor readings

public:
    // Default constructor
    SensorData() = default;

    // Move constructor (transfers ownership of resources)
    SensorData(SensorData&& other) noexcept
        : readings(std::move(other.readings)) {
        std::cout << "Move constructor called" << std::endl;
    }

    // Move assignment operator (transfers ownership of resources)
    SensorData& operator=(SensorData&& other) noexcept {
        if (this != &other) {
            readings = std::move(other.readings);
            std::cout << "Move assignment operator called" << std::endl;
        }
        return *this;
    }

    // Disable copy constructor and copy assignment to enforce move semantics
    SensorData(const SensorData&) = delete;
    SensorData& operator=(const SensorData&) = delete;

    // Method to add a new sensor reading
    void addReading(int value) {
        readings.push_back(value);
    }

    // Method to get a reading at a specific index
    int getReading(size_t index) const {
        if (index < readings.size()) {
            return readings[index];
        }
        throw std::out_of_range("Index out of range");
    }

    // Method to move data from another SensorData object
    void moveDataFrom(SensorData&& other) {
        readings = std::move(other.readings);  // Transfers ownership of data
        std::cout << "Data moved from rvalue reference (temporary)" << std::endl;
    }

    // Overloaded method to move data from an lvalue reference
    void moveDataFrom(SensorData& other) {
        readings = std::move(other.readings);  // Transfers ownership of data
        std::cout << "Data moved from lvalue reference (existing object)" << std::endl;
    }

    // Method to print all sensor readings
    void printReadings() const {
        std::cout << "Sensor Readings: ";
        for (int reading : readings) {
            std::cout << reading << " ";
        }
        std::cout << std::endl;
    }
};

int main() 
{
    // Create a SensorData object and add some readings
    SensorData data1;
    data1.addReading(100);
    data1.addReading(200);
    data1.addReading(300);

    // Print data1 readings
    data1.printReadings();

    // Move data1 to data2 using the move constructor
    SensorData data2(std::move(data1));

    // Print data2 readings after move
    data2.printReadings();

    // Verify that data1 is now empty
    data1.printReadings();  // Should be empty

    // Create another SensorData object and add readings
    SensorData data3;
    data3.addReading(400);
    data3.addReading(500);

    // Use move assignment operator to transfer data from data3 to data2
    data2 = std::move(data3);

    // Print data2 readings after move assignment
    data2.printReadings();

    // Verify that data3 is now empty
    data3.printReadings();  // Should be empty

    // Move data back to data1 using moveDataFrom method (rvalue)
    data1.moveDataFrom(std::move(data2));

    // Print data1 readings after moving data back
    data1.printReadings();

    return 0;
}