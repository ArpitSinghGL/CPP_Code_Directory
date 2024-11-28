#include <bits/stdc++.h>

using namespace std;

template < typename T >
T adder(T v)
{
    cout << __PRETTY_FUNCTION__ << endl;
    return v;
}

// Variadic function Templates
template < typename T , typename... Args >
T adder(T first , Args... args)
{
    cout << __PRETTY_FUNCTION__ << endl;
    return first + adder(args...);
}

int main()
{
    cout << endl;
    cout << adder(1 , 2 , 3 , 4) << endl;
    cout << endl;
    cout << adder(10 , 20 , 30 , 40 , 50) << endl;
    cout << endl;
    return 0;
}