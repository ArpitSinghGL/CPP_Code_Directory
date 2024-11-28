#include <bits/stdc++.h>

using namespace std;

template < typename T >
T adder(T arg)
{
    cout << __PRETTY_FUNCTION__ << endl;
    return arg;
}

template < typename T , typename ... Args>
T adder(T firstArg , Args ... args)
{
    cout << __PRETTY_FUNCTION__ << endl;
    return firstArg + adder(args ...);
}

int main()
{
    cout << endl;
    cout << adder(1 , 1.1f , 2 , 23.34567 , 10.5f) << endl;
    cout << endl;
    return 0;
}