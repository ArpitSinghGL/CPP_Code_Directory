//  * Threads that waste CPU cycles

#include <stdio.h>
#include <thread>
#include <chrono>
#include <unistd.h>

// a simple function that wastes CPU cycles "forever"
void cpu_waster() {
    while(1)
    {
        printf("CPU Waster Process ID: %d\n", getpid());
        printf("CPU Waster Thread ID %d\n", std::this_thread::get_id());
        printf("============================================================\n");
        std::this_thread::sleep_for(std::chrono::seconds(10));

    }

}

int main() {
    printf("Main Process ID: %d\n", getpid());
    printf("Main Thread ID: %d\n", std::this_thread::get_id());
    std::thread thread1(cpu_waster);
    std::thread thread2(cpu_waster);

    while(true) 
    { // keep the main thread alive "forever"
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    return 0;
}
