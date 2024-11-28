#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Functor
{
    int lastResult = -1;

    void operator () (int n)
    {
        lastResult = n;
        cout << lastResult << " ";
    }
};

int main()
{
    vector <int> v {10 , 20 , 30 , 40 , 50};

    // Utilizing function-objects or functors
    for_each( v.begin() , v.end() , Functor() );

    cout << endl;

    // The below code using lambda-expression is eqivalent to the above code utilizing function-objects or functors

    int lastResult = -1;

    auto updateLastResult = [ &lastResult ] ( int n ) { 
        lastResult = n;
        cout << lastResult << " ";
    };

    for_each(begin(v) , end(v) , updateLastResult);

    cout << endl;

    return 0;
}