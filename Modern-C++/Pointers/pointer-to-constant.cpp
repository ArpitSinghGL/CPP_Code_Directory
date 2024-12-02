#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << endl;

    int a = 10;

    int b = 20;

    // non-constant Pointer to constant integer
    const int * ptr = &a;

    cout << "a: " << a << endl;

    cout << "&a: " << &a << endl;

    cout << "b: " << b << endl;

    cout << "&b: " << &b << endl;

    cout << "ptr: " << ptr << '\n';

    cout << "*ptr: " << *ptr << '\n';

    cout << endl;

    // The address of the memory-location stored in ptr can be changed, but the value in that memory-location cannot be changed 
    // using that pointer.

    ptr = &b;

    cout << "a: " << a << endl;

    cout << "&a: " << &a << endl;

    cout << "b: " << b << endl;

    cout << "&b: " << &b << endl;

    cout << "ptr: " << ptr << '\n';

    cout << "*ptr: " << *ptr << '\n';

    cout << endl;

    // The value stored in the memory-address stored in the pointer cannot be changed using the pointer as shown below.
    // In other words, the value of b cannot be changed using ptr.
    
    // *ptr = 50;  // error: assignment of read-only location '* ptr'

    // But, the value of b can be changed directly without using ptr.
    b = 50;

    cout << "a: " << a << endl;

    cout << "&a: " << &a << endl;

    cout << "b: " << b << endl;

    cout << "&b: " << &b << endl;

    cout << "ptr: " << ptr << '\n';

    cout << "*ptr: " << *ptr << '\n';

    cout << '\n';

    return 0;
}
