#include <iostream>

#include <thread>

#include <chrono>

#include <vector>

using namespace std;

void printHelloWorld()
{
    cout << "thread id: " << this_thread :: get_id() << " has started executing..." << endl;
    this_thread :: sleep_for( chrono :: seconds(5) );
    cout << "thread id: " << this_thread :: get_id() << " says Hello World !" << endl;
    cout << "thread id: " << this_thread :: get_id() << " has finished execution !" << endl;
    cout << endl;
    return;
}

int main()
{
    cout << "Main thread: " << this_thread :: get_id() << " has started execution..." << endl;

    cout << endl;

    vector <thread> threads;

    for(int i = 0 ; i < 10 ; i++)
    {
        threads.push_back( thread(printHelloWorld) );
    }

    for(int i = 0 ; i < 10 ; i++)
    {
        threads[i].join();
    }

    cout << "Main thread: " << this_thread :: get_id() << " has finished execution." << endl;

    return 0;
}