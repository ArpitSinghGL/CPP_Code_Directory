#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void task()
{
    cout << "thread id: " << this_thread :: get_id() << " has started executing..." << endl;

    this_thread :: sleep_for( chrono :: seconds(10) );

    cout << "thread id: " << this_thread :: get_id() << " has finished executing !" << endl;

    return;
}

int main()
{
    cout << "Main thread: " << this_thread :: get_id() << " has started executing..." << endl;
    thread t1(task);
    thread t2(task);
    cout << "Main thread: " << this_thread :: get_id() << " has finished executing..." << endl;
    return 0;
}