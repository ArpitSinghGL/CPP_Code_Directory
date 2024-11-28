#include <bits/stdc++.h>

using namespace std;

template < typename T >
class ShrdPtrImpl
{
    private:

    T* ptr;

    public:

    ShrdPtrImpl(T value) : ptr(new T(value))
    {
        cout << "Parameterized constructor invoked..." << endl;   
    }

    friend ShrdPtrImpl<T> make_shared_custom (T value);

    void get()
    {
        cout << ptr;
    }

    T operator * ()
    {
        return *(ptr);
    }

};

template <typename T>
ShrdPtrImpl<T> make_shared_custom (T value)
{
    ShrdPtrImpl <T> shrd_ptr(value);
    return shrd_ptr;
}


int main()
{
    ShrdPtrImpl <int> shrd_ptr = make_shared_custom <int> (10);

    shrd_ptr.get();

    cout << endl;

    cout << *shrd_ptr << endl;

    cout << endl;

    // Shallow-Copy
    ShrdPtrImpl <int> shrd_ptr1 = shrd_ptr;  // Default copy-assignment operator invoked

    shrd_ptr1.get();

    cout << endl;

    cout << *shrd_ptr1 << endl;

    return 0;
}