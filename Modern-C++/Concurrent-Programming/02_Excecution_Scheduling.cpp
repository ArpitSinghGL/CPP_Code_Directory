/**
 * Two threads Processing Sensor Sample
 */

#include<stdio.h>
#include <thread>
#include <chrono>
#include <stdint.h>

bool Sensor_process = true;

void Process_Sensor_Data(const char* name) {
    uint64_t Sensor_Sample = 0;
    while (Sensor_process) {
        Sensor_Sample++;
        //std::this_thread::sleep_for(std::chrono::nanoseconds(1));
    }
    printf("%s used %u sensor samples \n", name, Sensor_Sample);
}

int main() {
    std::thread App_A(Process_Sensor_Data, "APP_A");
    std::thread App_B(Process_Sensor_Data, "APP_B");

	printf("App_A and App_B are processing sensor samples...\n");
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    Sensor_process = false;
    App_A.join();
    App_B.join();
}
