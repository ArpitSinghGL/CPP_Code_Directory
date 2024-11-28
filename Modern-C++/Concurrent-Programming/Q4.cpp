#include <bits/stdc++.h>

#include <threads.h>

#include <mutex>

using namespace std;

int sharedVariable = 0;

std::mutex counterMutex;

void increment()
{
    for(int i = 0 ; i < 1000 ; i++)
    {
        counterMutex.lock();
        ++sharedVariable;
        counterMutex.unlock();
    }
}

int main()
{
    thread t1(increment);
    thread t2(increment);
    thread t3(increment);

    t1.join();
    t2.join();
    t3.join();

    cout << "The final value of the shared variable is: " << sharedVariable << endl;

    return 0;
}