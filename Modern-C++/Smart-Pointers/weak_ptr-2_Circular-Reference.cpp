#include <bits/stdc++.h>

using namespace std;

class B;

class A
{
    public:

    shared_ptr <B> shrd_ptr_b;

    ~A()
    {
        cout << "Destructor of class A is called...." << endl;
    }

};

class B
{
    public:

    shared_ptr <A> shrd_ptr_a;

    ~B()
    {
        cout << "Destructor of clas B is called....." << endl;
    }
};

// Note that the memory location alloted to a shared pointer is deallocated only when the reference count of that memory address 
// becomes 0. Otherwise, even if there is a single instance of shared_ptr pointing to that memory address, that memory address
// is not deallocated.
// This is because, if the memory address stored in a shared_ptr is deallocated when the reference count of that memory address
// is not zero i.e. when that memory address is still being shared by other shared pointers then this would result in the creation
// dangling pointers which is something that smart-pointers aim to overcome.
// This property may result in the problem of circular-reference.
// In order to resolve this issue of circular-reference, weak pointers are used.

int main()
{
    cout << endl;

    shared_ptr <A> aptr( new A() );
    shared_ptr <B> bptr ( new B() );

    aptr -> shrd_ptr_b = bptr;
    bptr -> shrd_ptr_a = aptr;

    // Both shared pointers aptr and bptr -> shrd_ptr_b point to the same memory address
    cout << "aptr.get(): " << aptr.get() << endl;
    cout << "(bptr -> shrd_ptr_a).get(): " << (bptr -> shrd_ptr_a).get() << endl;

    cout << endl;

    // Both shared pointers bptr and aptr -> shrd_ptr_b point to the same memory address
    cout << "bptr.get(): " << bptr.get() << endl;
    cout << "(aptr -> shrd_ptr_b).get(): " << (aptr -> shrd_ptr_b).get() << endl;

    cout << endl;

    // Printing the reference count of the memory address stored in each shared pointer
    cout << "aptr.use_count(): " << aptr.use_count() << endl;
    cout << "(bptr -> shrd_ptr_a).use_count(): " << (bptr -> shrd_ptr_a).use_count() << endl;
    cout << "bptr.use_count(): " << bptr.use_count() << endl;
    cout << "(aptr -> shrd_ptr_b).use_count(): " << (aptr -> shrd_ptr_b).use_count() << endl;

    cout << endl;

    // The shared pointers aptr and bptr go out of scope when the main function gets executed.
    // Since shared_ptr objects aptr and bptr are present in the stack memory, after the completion of the main function,
    // aptr and bptr go out of scope and are automatically deleted by the compiler.
    //  Note that even after the shared_ptr objects aptr and bptr go out of scope after the completion of the main function,
    // and are deleted by the compiler automatically, the destructors are not invoked, which means that the memory address stored
    // in aptr and bptr is not deallocated even though aptr and bptr are deleted.

    // This is because:
    // 1. If the memory address stored in aptr is deallocated first, then (bptr -> shrd_ptr_a) which was also pointing to the 
    // same memory address, now becomes a dangling pointer.
    // 2. If the memory address stored in bptr is deallocated first, then (aptr -> shrd_ptr_b) which was also pointing to the 
    // same memory address, now becomes a dangling pointer.

    // This is refered to as the problem of circular-reference.

    // In order to resolve this problem, weak pointers are used.

    return 0;
}