#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;
std::mutex counterMutex;

void incrementCounter(int iterations) 
{
    for (int i = 0; i < iterations; ++i) 
    {
        // Lock the mutex before accessing the shared resource
        // std::lock_guard<std::mutex>guard(counterMutex);
        bool result = counterMutex.try_lock();
        if(result == true)
        {
            cout << "Mutex is acquired....." << endl;
            ++counter;  // Critical section (shared resource)
            counterMutex.unlock();
        }
        else
        {
            cout << "Mutex is not acquired ..." << endl;
        }
    }
}

void decrementCounter(int iterations)
{
    for(int i = 0 ; i < iterations ; i++)
    {
        counterMutex.lock();
        --counter;
        counterMutex.unlock();
    }
}

int main() 
{
    int iterations = 100000;
    
    std::thread t1(incrementCounter, iterations);
    std::thread t2(decrementCounter, iterations);
    
    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << std::endl;
    return 0;
}