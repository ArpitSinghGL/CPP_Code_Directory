#include <bits/stdc++.h>

using namespace std;

int getNumber()
{
    return 5;
}

int add(int a , int b)
{
    return a + b;
}

void goodMorning()
{
    cout << "Good morning !!!" << endl;
}

void goodEvening()
{
    cout << "Good evening !!!" << endl;
}

void goodNight()
{
    cout << "Good night !!!" << endl;
}

void greeting( void (*functionPtr) () )
{
    functionPtr();
}

// A void pointer is a pointer that has no associated data type with it. A void pointer can hold an address of any type and 
// can be typecasted to any type.
// 1. void pointers cannot be dereferenced.
// 2. The C standard doesn’t allow pointer arithmetic with void pointers.

int main()
{
    cout << endl;

    int a = 10;
    char ch = 'a';

    void* ptr = &a;
    cout << "Address of integer variable a: " << ptr << endl;
    cout << *(int*)ptr << endl;

    cout << endl;

    ptr = &ch;
    cout << "Address of character variable ch: " << ptr << endl;
    cout << *((char*)ptr) << endl;

    cout << endl;

    // Note that the function-name i.e. "getNumber" gives the address of the getNumber function.
    // This address is being typecasted to a void pointer (void*) as a void pointer can hold the address of any type and can be
    // typecasted to any type.
    cout << "Address of the function getNumber: " << (void*) getNumber << endl;

    cout << endl;

    // Creating a function-pointer for the getNumber function
    // Syntax of a function pointer:
    // return-type (*name_of_function-pointer) (parameter-types)
    int (*funcPtr_getNumber) () = getNumber;
    cout << "Address stored in funcPtr_getNumber: " << (void*)funcPtr_getNumber << endl;
    cout << "funcPtr_getNumber(): " << funcPtr_getNumber() << endl;

    cout << endl;

    // Note that cout does not know to print the address of a function-pointer, therefore if we try to print a function-pointer
    // directly using cout it simply prints 1, if the function-pointer is not null. In order to get the actual address of the
    // function-pointer, we need to typecast it to a void-pointer (void*) as cout knows to print the address stored in a void pointer.

    // Creating a function-pointer for the add function
    int (*funcPtr_add) (int , int) = add;
    cout << "Address of the function add stored in funcPtr_add: " << (void*)funcPtr_add << endl;
    cout << "funcPtr_add(): " << funcPtr_add(3 , 5) << endl;

    cout << endl;

    // Passing a function as an argument inside another function with the help of function-pointers
    greeting(goodMorning);
    greeting(goodEvening);
    greeting(goodNight);

    cout << endl;

    return 0;
}
