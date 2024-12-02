#include <iostream>

#include <algorithm>

#include <vector>

#include <functional>

using namespace std;


class Functor
{
    private: 

    int sum;

    public: 

    Functor() : sum(0)
    {
        cout << "Default constructor is invoked...." << endl;
    }

    Functor(int initialSum) : sum(initialSum)
    {
        cout << "Parameterised constructor is invoked..." << endl;
    }

    void operator () (int element)
    {
        cout << element << " ";
        sum += element;
    }

    int getSum()
    {
        return sum;
    }
};

int main()
{
    cout << endl;

    vector <int> v {10 , 20 , 30 , 40 , 50};

    int sum = 100;

    cout << "Initial value of sum: " << sum << endl;

    // Lambda functions are anonymous or unnamed functions

    for_each(begin(v) , end(v) , [ &sum ] (int element) {
        cout << element << " ";
        sum += element;
    } );

    cout << endl;

    cout << "Final value of sum: " << sum << endl;

    cout << endl;

    Functor functor1;

    for_each(begin(v) , end(v) , std :: ref (functor1) );

    cout << endl;

    cout << "sum: " << functor1.getSum() << endl;

    cout << endl;

    Functor functor2(100);

    for_each(v.begin() , v.end() , std :: ref (functor2) );

    cout << endl;

    cout << "sum: " << functor2.getSum() << endl;

    cout << endl;

    return 0;
}
