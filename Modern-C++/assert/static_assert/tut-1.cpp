#include <iostream>
#include <cassert>

using namespace std;

// static_assert() performs assertion check at compile-time. 
// If the assertion check fails at compile-time, a compile-time error is thrown.

constexpr int add(int a , int b)
{
    return a + b;
}

int main()
{
    constexpr int age = -7;

    // static_assert(age > 0 , "Age cannot be less than zero");

    static_assert( add(2 , 2) == 4 , "2+2 == 4");
    cout << "Assertion: add(2 , 2) == 4 is true" << endl;

    static_assert( sizeof(int) == 4 , "int -> 2 bytes");
    cout << "Assertion: int -> 4 bytes is true" << endl;

    return 0;
}