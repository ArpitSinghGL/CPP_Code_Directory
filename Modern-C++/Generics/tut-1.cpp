#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

template < typename T1 , typename T2 >
void foo(T1 input1 , T2 input2)
{
    cout << input1 <<  " " << typeid(input1).name() << endl;
    cout << input2 << " " << typeid(input2).name() << endl;
}

int main()
{
    foo <int , float> (10 , 20.234f);
    return 0;
}