#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1, m2;

void thread1() {
    std::lock_guard<std::mutex> lock1(m1);  // Lock m1 first
    std::this_thread::sleep_for(std::chrono::milliseconds(50));  // Simulate some work
    std::lock_guard<std::mutex> lock2(m2);  // Then lock m2
    std::cout << "Thread 1 acquired both locks" << std::endl;
}

void thread2() {
    std::lock_guard<std::mutex> lock1(m2);  // Lock m2 first
    std::this_thread::sleep_for(std::chrono::milliseconds(50));  // Simulate some work
    std::lock_guard<std::mutex> lock2(m1);  // Then lock m1
    std::cout << "Thread 2 acquired both locks" << std::endl;
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);
    
    t1.join();
    t2.join();
    
    return 0;
}
