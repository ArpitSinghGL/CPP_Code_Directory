#include <iostream> 

using namespace std;

// Function Templates

template < typename T1 , typename T2 >

auto multiply(T1 x , T2 y)
{
    return x * y;
}

int main()
{
    // auto is used for automatic type deduction
    
    auto product = multiply(10 , 20.12f);

    cout << product << endl;

    return 0;
}