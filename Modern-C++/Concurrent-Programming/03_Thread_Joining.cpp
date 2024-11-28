// Main() initiating Thread1

#include <stdio.h>
#include <thread>
#include <chrono>

void Thread1_CallBack() {
    printf("Thread1 started & waiting to run its callback\n");
    std::this_thread::sleep_for(std::chrono::seconds(3));
    printf("Thread1 callback is completed\n");
}

int main() {
    printf("Main Function starting Thread1\n");
    std::thread Thread1(Thread1_CallBack);
    printf("  Is Thread1 active? %s\n", Thread1.joinable() ? "true" : "false");

    printf("Main Function still running.\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    printf("  Is Thread1 active? %s\n", Thread1.joinable() ? "true" : "false");

    printf("Main() waits for Thread1 to finish and join...\n");
    Thread1.join();
    printf("  Is Thread1 active? %s\n", Thread1.joinable() ? "true" : "false");

    printf("Main() and Thread1 both completed the excecution\n");
}
