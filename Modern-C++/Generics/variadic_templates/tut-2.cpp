#include <bits/stdc++.h>

using namespace std;

// Variadic Template Functions
template < typename T > 
void print(T arg)
{
    cout << __PRETTY_FUNCTION__ << endl;
    cout << arg << endl;
    return;
}

template < typename T , typename ... Args >
void print(T firstArg , Args ... remainingArgs)
{
    cout << __PRETTY_FUNCTION__ << endl;
    cout << firstArg << endl;
    print(remainingArgs ...);
    return;
}

int main()
{
    cout << endl;
    print(1 , 2 , 3 , "Oliver Queen" , 4 , 5 , 1.223f , 567.98765 , "Bruce Wayne");
    cout << endl;
    return 0;
}