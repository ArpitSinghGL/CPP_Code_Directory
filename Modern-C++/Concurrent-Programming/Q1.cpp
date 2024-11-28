#include <bits/stdc++.h>

#include <threads.h>
#include <mutex>

using namespace std;

void printHello()
{
    cout << "Hello";
    return;
}

void printWorld()
{
    cout << "World";
    return;
}

int main()
{
    thread thread1(printHello);
    thread thread2(printWorld);

    thread1.join();
    thread2.join();

    return 0;
}