#include <iostream>

using namespace std;

void f(int& lval)
{
    cout << "lvalue function: " << lval << endl;
}

void f(const int& constlval)
{
    cout << "const lvalue function: " << constlval << endl;
}

void f(int&& rval)
{
    cout << "rvalue function: " << rval << endl;
}

int main()
{
    int a = 10;

    f(a);

    f(10);

    f(std::move(a));

    f( static_cast< int&& >(a) );

    return 0;
}
