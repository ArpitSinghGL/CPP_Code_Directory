#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Using a normal function
void func(int n)
{
    cout << n << " ";
}

// Using a function-object or functor
struct PrintFunctor
{
    void operator () (int n)
    {
        cout << n << " ";
    }  
};

int main()
{
    // Using initializer-list to initialize the vector
    vector <int> v {1 , 2 , 3 , 4 , 5};

    // 1. Using a normal range-based for-loop
    for(auto element : v)
    {
        cout << element << " ";
    }

    cout << endl;

    // 2. Using the for_each() function from the algorithm library and a normal function
    for_each(begin(v) , end(v) , func);

    cout << endl;

    // 3. Using a function pointer and for_each() function from the algorithm library
    void ( *funcPointer ) (int) = func;

    for_each(v.begin() , v.end() , funcPointer);

    cout << endl;

    // 4. Using the for_each() function and inline-Lambda-Expression
    for_each(v.begin() , v.end() , [] (int n) { cout << n << " "; } );

    cout << endl;

    // 5. Using for_each() and external lambda-expression
    auto print = [] (int n) { cout << n << " "; };

    for_each(begin(v) , end(v) , print);

    cout << '\n';

    // 6. Using for_each() and a named function object
    PrintFunctor printFunctor;
    for_each(v.begin() , v.end() , printFunctor);

    cout << endl; 

    // 7. Using for_each() and an anonymous function object
    for_each(v.begin() , v.end() , PrintFunctor() );

    cout << endl;

    return 0;
}