#include <iostream>

#include <thread>

#include <threads.h>

#include <mutex>

using namespace std;

int counter = 1;

void increment_thread1()
{
    counter *= 2;
}

void increment_thread2()
{
    counter += 5;
}

int main()
{
    thread t1(increment_thread1);  // 1 * 2 = 2  or  6 * 2 = 12
    thread t2(increment_thread2);  // 2 + 5 = 7  or  1 + 5 = 6
    t1.join();
    t2.join();
    cout << "The final value of counter is: " << counter << endl;
    return 0;
}