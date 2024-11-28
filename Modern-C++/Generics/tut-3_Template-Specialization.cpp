#include <iostream>

using namespace std;

template < typename T >
bool equal(T x , T y)
{
    return (x == y);
}

// Template Specialization
template <>
bool equal <float> (float x , float y)
{
    cout << "Template specialization for floating-point numbers !" << endl;
    return (x == y);
}

// Template Specialization
template <>
bool equal <double> (double a , double b)
{
    cout << "Template specialization for double values !" << endl;
    return (a == b);
}

int main()
{
    cout << equal <int> (2 , 2) << endl;
    cout << equal <int> (2 , 3) << endl;
    cout << equal <float> (11.234f , 11.2345f) << endl;
    cout << equal <double> (123.123 , 123.1234) << endl;
    return 0;
}