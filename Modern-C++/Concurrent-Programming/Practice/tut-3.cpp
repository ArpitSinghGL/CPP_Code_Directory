#include <iostream>

#include <thread>

#include <chrono>

using namespace std;

void printHelloWorld()
{
    cout << "thread_id: " << this_thread :: get_id() << " waiting to execute..." << endl;
    this_thread :: sleep_for( chrono :: seconds(10) );
    cout << "thread id: " << this_thread :: get_id() << " says: Hello World !" << endl; 
    cout << "thread_id: " << this_thread :: get_id() << " finished execution !" << endl;
}

int main()
{
    cout << "Main Thread id: " << this_thread :: get_id()  << endl;

    thread t1(printHelloWorld);

    t1.join();

    printHelloWorld();

    return 0;
}