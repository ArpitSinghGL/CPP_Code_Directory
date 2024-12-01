#include <iostream>

#include <typeinfo>

#include <vector>

using namespace std;

auto& findElement1(vector<int>& vec , int index)
{
    // Even though vec[index] is actually a reference to v[index], auto as the return-type will actually return a copy of 
    // the value stored in v[index] and not the actual reference to v[index].
    // In order to return a reference using auto, we have to keep the return type as auto&
    return vec[index];
}

auto findElement2(vector <int>& vec , int index)
{
    return vec[index];
}

int main()
{
    cout << endl;

    // auto performs a very loose type-deduction purely based on the value (or rvalue)

    int a = 10;
    auto a1 = a;

    cout << "typeid(a).name(): " << typeid(a).name() << endl;
    cout << "typeid(a1).name(): " << typeid(a1).name() << endl;

    // auto does not preserves const qualifiers

    const int b = 20;
    auto b1 = b;

    cout << "typeid(b).name(): " << typeid(b).name() << endl;
    cout << "typeid(b1).name(): " << typeid(b1).name() << endl;

    // b = 30;
    b1 = 30;

    cout << "b1: " << b1 << endl;

    // auto does not preserves references

    int c = 50;
    int& cRef = c;
    auto cRef1 = cRef;

    cout << "typeid(c).name(): " << typeid(c).name() << endl;
    cout << "typeid(cRef).name(): " << typeid(cRef).name() << endl;
    cout << "typeid(cRef1).name(): " << typeid(cRef1).name() << endl;

    // Modifying cRef to modify c
    cRef = 60;

    cout << "c: " << c << endl;
    cout << "cRef: " << cRef << endl;

    // Modifying cRef1 does not modify c as reference was not preserved by auto
    cRef1 = 100;

    cout << "c: " << c << endl;
    cout << "cRef: " << cRef << endl;
    cout << "cRef1: " << cRef1 << endl;

    cout << endl;


    // Another example demonstrating that auto does not preserve reference

    vector <int> v {10 , 20 , 30 , 40 , 50};

    auto v2 = findElement1(v , 2);

    cout << "v2: " << v2 << endl;
    cout << "v[2]: " << v[2] << endl;

    v2 = 100;

    cout << "v2: " << v2 << endl;
    cout << "The value of v[2] is: " << v[2] << endl;

    cout << endl;

    // auto& v3 = findElement2(v , 3);  // error: invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'
    
    const auto& v3 = findElement2(v , 3);

    cout << "v[3]: " << v[3] << endl;
    cout << "v3: " << v3 << endl;

    // v3 += 100;  // error: assignment of read-only reference 'v3'

    cout << endl;

    return 0;
}
