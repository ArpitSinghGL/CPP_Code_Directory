#include <iostream>

using namespace std;

void static_foo()
{
    // The scope of static variable static_x is the block of function static_foo
    // If we try to access static_x from anywhere outside the function static_foo then we will get an error.
    static int static_x = 0;

    static_x += 1;

    cout << "The value of static_x is: " << static_x << endl;

    return;
}

void foo()
{
    int x = 0;

    x += 1;

    cout << "The value of x is: " << x << endl;

    return;
}

int main()
{
    cout << endl;

    for(int i = 0 ; i < 10 ; i++)
    {
        foo();
    }

    cout << endl;

    for(int i = 0 ; i < 10 ; i++)
    {
        static_foo();
    }

    cout << endl;

    // Trying to access static_x from outside it's scope i.e. outside the function static_foo
    // cout << "The value of static_x is: " << static_x << endl;  //  error: 'static_x' was not declared in this scope

    return 0;
}
