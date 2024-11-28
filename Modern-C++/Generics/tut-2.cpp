#include <iostream>
#include <typeinfo>

using namespace std;

template < typename T , int N >
void foo(T n)
{
    for(int i = 0 ; i < N ; i++)
    {
        cout << n << " " << typeid(n).name() << endl;
        cout << N << " " << typeid(N).name() << endl;
        cout << endl;
    }
}

int main()
{
    foo <int , 5> (5);
    return 0;
}