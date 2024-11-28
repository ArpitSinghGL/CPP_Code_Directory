#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Syntax for lambda functions
// [ capture state ] ( params ) { body }

void func(int n)
{
    cout << n << " ";
}

int main()
{
    // Initializing the vector using an initializer-list
    vector <int> v {1 , 3 , 2 , 5 , 6};

    // Using range-based for-loop
    for(auto ele : v)
    {
        cout << ele << " ";
    }

    cout << endl;

    // Using for_each() function along with the lambda expression
    for_each( v.begin() , v.end() , [] (int n) {
        cout << n << " ";
    } );

    cout << endl;

    // Using for_each() along with a normal function
    for_each(begin(v) , end(v) , func);

    cout << endl;

    // Using for_each() along with function pointer
    void (*funcPtr) (int) = func;

    for_each(begin(v) , end(v) , funcPtr);

    cout << endl;

    return 0;
}