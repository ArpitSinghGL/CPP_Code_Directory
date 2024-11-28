#include <bits/stdc++.h>

using namespace std;

class B;

class A
{
    public:

    shared_ptr <B> shrd_ptr_b;

    ~A()
    {
        cout << "The destructor of class A is invoked...." << endl;
    }
};

class B
{
    public:

    weak_ptr <A> weak_ptr_a;

    ~B()
    {
        cout << "The destructor of class B is invoked......" << endl;
    }
};

int main()
{
    cout << endl;

    shared_ptr <A> aptr = make_shared <A> ();
    shared_ptr <B> bptr = make_shared <B> ();

    cout << "aptr.get(): " << aptr.get() << endl;
    cout << "bptr.get(): " << bptr.get() << endl;
    cout << "aptr.use_count(): " << aptr.use_count() << endl;
    cout << "bptr.use_count(): " << bptr.use_count() << endl;

    cout << endl;

    aptr -> shrd_ptr_b = bptr;
    bptr -> weak_ptr_a = aptr;

    cout << "(aptr -> shrd_ptr_b).get(): " << (aptr -> shrd_ptr_b).get() << endl;
    cout << "(bptr -> weak_ptr_a).lock(): " << (bptr -> weak_ptr_a).lock() << endl;
    cout << "aptr.use_count(): " << aptr.use_count() << endl;  // 1
    cout << "bptr.use_count(): " << bptr.use_count() << endl;  // 2
    cout << "(aptr -> shrd_ptr_b).use_count(): " << (aptr -> shrd_ptr_b).use_count() << endl;
    cout << "(bptr -> weak_ptr_a).use_count(): " << (bptr -> weak_ptr_a).use_count() << endl;

    cout << endl;

    return 0;
}