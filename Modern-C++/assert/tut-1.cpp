#include <iostream>
#include <cassert>

using namespace std;

int main()
{
    int age = -7;

    assert(age > 0 && "age was less than 0");

    // Note that assert() performs runtime assertion-check.
    // The program crashes if the assertion is not true.
    // Therefore, none of the code written after the assertion-check executes if the assertion fails.

    cout << "This cout statement comes after the assert" << endl;

    return 0;
}