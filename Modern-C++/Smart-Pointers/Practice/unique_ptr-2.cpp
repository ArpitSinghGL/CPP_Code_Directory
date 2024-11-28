#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << endl;

    unique_ptr<int> ptr1(new int(10));

    cout << "Before transfer of ownership from ptr1 to ptr2: " << endl;

    cout << "Value stored at the address pointed by ptr1 is: " << *ptr1 << endl;

    cout << "The address pointed by ptr1 is: " << ptr1.get() << endl;

    unique_ptr<int> ptr2;

    cout << "The address pointed by ptr2 is: " << ptr2.get() << endl;

    // cout << "The value stored at the address pointed by ptr2 is: " << *ptr2 << endl;

    cout << endl;

    // ptr2 = ptr1;  // Compile-time error is thrown as only one unique_ptr can take ownership of an object.
    // More than one unique pointers can not share ownership of an object.

    // But, transfer of ownership is possible by using the std::move() function as shown below:
    ptr2 = move(ptr1);

    cout << "After transfer of ownership from ptr1 to ptr2: " << endl;

    // cout << "Value stored at the address pointed by ptr1 is: " << *ptr1 << endl;

    cout << "The address pointed by ptr1 is: " << ptr1.get() << endl;

    cout << "The address pointed by ptr2 is: " << ptr2.get() << endl;

    cout << "The value stored at the address pointed by ptr2 is: " << *ptr2 << endl;

    cout << endl;

    cout << "Transferring the ownership from ptr2 back to ptr1: " << endl;

    ptr1 = move(ptr2);

    cout << "*ptr1: " << *ptr1 << endl;

    cout << "ptr1.get(): " << ptr1.get() << endl;

    cout << "ptr2.get(): " << ptr2.get() << endl;

    cout << endl;

    // Pointing ptr2 to another integer variable using the reset function

    ptr2.reset(new int(10));

    cout << "Pointing ptr2 to another integer variable using the reset function: " << endl;

    cout << "*ptr1: " << *ptr1 << endl;

    cout << "ptr1.get(): " << ptr1.get() << endl;

    cout << "*ptr2: " << *ptr2 << endl;

    cout << "ptr2.get(): " << ptr2.get() << endl;

    cout << endl;

    return 0;
}