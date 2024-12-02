#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << '\n';

    int a = 10 , b = 20;

    int * const ptr = &a;

    cout << "a: " << a << '\n';

    cout << "&a: " << &a << '\n';

    cout << "b: " << b << '\n';

    cout << "&b: " << &b << '\n';

    cout << "ptr: " << ptr << '\n';

    cout << "*ptr: " << *ptr << '\n';

    cout << endl;

    // The value of a can be changed using ptr as shown below

    *ptr = 50;

    cout << "a: " << a << '\n';

    cout << "&a: " << &a << '\n';

    cout << "ptr: " << ptr << '\n';

    cout << "*ptr: " << *ptr << '\n';

    cout << endl;

    // But the address of the memory-location that ptr points to is fixed and cannot be changed.
    // Basically, ptr contains the address of 'a' and it cannot be made to store the address of 'b' as shown below.
    // ptr is a read-only variable.

    // ptr = &b;  // error: assignment of read-only variable 'ptr'

    cout << endl;

    return 0;
}
