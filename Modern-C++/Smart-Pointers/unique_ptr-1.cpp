#include <bits/stdc++.h>

using namespace std;

// Using raw pointers
int func1()
{
    int* ptr = new int(10);
    cout << "Value: " << *ptr << endl;
    cout << "Address: " << ptr << endl;
    if( *ptr == 1 )
    {
        return *ptr;
    }
    // Note that if the condition is true, the function returns without freeing the heap memory location stored in ptr.
    // Since ptr is a variable that is present in the scope of the function, it is destroyed as soon as the function returns
    // but the memory location pointed by ptr has to be freed explicitly as the memory was dynamically allocated in heap.
    // Note that ptr resides in the stack memory whereas the memory location it points to is a memory location in the heap segment.
    // Thus, if the condition holds then it would lead to a memory-leak as a part of the heap memory is not deallocated even 
    // after use and therefore that memory location is no longer available for further use.
    delete ptr;
    return 0;
}

// Using unique pointers
int func2()
{
    unique_ptr<int> ptr(new int(10));
    cout << "Value: " << *ptr << endl;
    cout << "Address in heap memory: " << ptr.get() << endl;
    if(*ptr == 10)
    {
        return *ptr;
    }
    // In case of a unique_ptr, the memory pointed to by the pointer is automatically deallocated when the unique_ptr 
    // goes out of scope. Therefore, we don't need to explicitly deallocate the memory address using the delete operator.
    // This makes unique_ptr more safe as compared to raw pointers when it comes to preventing memory-leaks. 
    return 0;
}

int main()
{
    cout << endl;

    int a = func1();
    cout << "a: " << a << endl;

    int b = func2();
    cout << "b: " << b << endl;

    cout << endl;

    return 0;
}