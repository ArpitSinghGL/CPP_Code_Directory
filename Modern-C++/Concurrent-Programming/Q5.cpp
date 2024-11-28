#include <iostream>
#include <threads.h>
#include <chrono>
#include <thread>

using namespace std;

void run()
{
    cout << "Execution of run function begins...." << endl;
    this_thread::sleep_for(chrono::seconds(10));
    cout << "Execution of run function ends...." << endl;
}

int main()
{
    thread t1(run);
    // t1.join();
    t1.detach();
    cout << "The execution of the main thread continues...." << endl;
    cout << "The main thread finishes its execution..." << endl;
    cout << "The main thread terminates...." << endl;
    return 0;
}