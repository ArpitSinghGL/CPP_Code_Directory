#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << endl;

    shared_ptr<int> shrd_ptr1 = make_shared<int>(10);

    cout << "*shrd_ptr1: " << *shrd_ptr1  << endl;

    cout << "shrd_ptr1.get(): " << shrd_ptr1.get() << endl;

    // Note that sharing of ownership was not possible with unique_ptr but it is possible with shared_ptr
    shared_ptr<int> shrd_ptr2 = shrd_ptr1;

    cout << "*shrd_ptr2: " << *shrd_ptr2 << endl;

    cout << "shrd_ptr2.get(): " << shrd_ptr2.get() << endl;

    // Printing the reference count
    cout << "shrd_ptr1.use_count(): " << shrd_ptr1.use_count() << endl;
    cout << "shrd_ptr2.use_count(): " << shrd_ptr2.use_count() << endl;
    // 2 because there are two shared pointers sharing the ownership of the integer 10

    cout << endl;

    // Revoking the ownership of shrd_ptr1 on the integer
    shrd_ptr1.reset();

    cout << "shrd_ptr1.get(): " << shrd_ptr1.get() << endl;

    cout << "shrd_ptr2.get(): " << shrd_ptr2.get() << endl;

    cout << "*shrd_ptr2: " << *shrd_ptr2 << endl;

    // Printing the reference count after revoking the ownership of shrd_ptr1 on the integer 10
    cout << "shrd_ptr2.use_count(): " << shrd_ptr2.use_count() << endl;  // 1
    cout << "shrd_ptr1.use_count(): " << shrd_ptr1.use_count() << endl;  // 0

    cout << endl;

    return 0;
}