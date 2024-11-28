#include <iostream>

#include <thread>

#include <threads.h>

#include <mutex>

#include <latch>

using namespace std;

int counter = 0;

mutex counterMutex;

latch lat(5);

void increment()
{
    counterMutex.lock();
    counter += 1;
    counterMutex.unlock();
    lat.count_down();
}

void decrement()
{
    lat.wait();
    counterMutex.lock();
    counter -= 1;
    counterMutex.unlock();
}

int main()
{
    thread threads[10];

    for(int i = 0 ; i <= 8 ; i += 2)
    {
        threads[i] = thread(increment);
        threads[i + 1] = thread(decrement);
    }
    for(int i = 0 ; i < 10 ; i++)
    {
        threads[i].join();
    }
    cout << "The final value of counter is: " << counter << endl;
    return 0;
}