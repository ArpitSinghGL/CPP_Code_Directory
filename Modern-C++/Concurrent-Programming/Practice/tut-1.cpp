#include <iostream>

#include <thread>

#include <mutex>

#include <chrono>

#include <cstddef>

#include <iomanip>

#include <numeric>

using namespace std;

mutex lockPrint;

unsigned long long evenSum = 0;

unsigned long long oddSum = 0;

void findEvenSum()
{
    for(int i = 0 ; i < 10000000 ; i++)
    {
        if(i % 2 == 0)
        {
            evenSum += i;
        }
    }
}

void findOddSum()
{
    for(int i = 0 ; i < 10000000 ; i++)
    {
        if(i % 2 == 1)
        {
            oddSum += i;
        }
    }
}

int main()
{
    // findEvenSum();
    // findOddSum();

    thread t1(findEvenSum);
    thread t2(findOddSum);

    t1.join();
    t2.join();

    cout << "Even sum: " << evenSum << endl;
    cout << "Odd sum: " << oddSum << endl;

    cout << "The main ends...." << endl;

    return 0;
}