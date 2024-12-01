#include<bits/stdc++.h>

using namespace std;

int global = 10;

int& fun1()
{
    return global; // returning a reference to global
}

int fun2()
{
    return global;
}

int& fun3(int& temp)
{
    return temp;
}

int& fun4(int temp)
{
    return temp;
}

int main()
{
    cout << endl;

    int a = 100;
    int& b = a;   // b is a reference to a
    int& c = b;   // c is a reference to b that means c is indirectly a reference to a
    int d = c;    // d is not a reference to c. It stores a copy of the value stored in c. 
    // This means that d is independent of a , b and c. Any 

    cout << "a: " << a << endl;  // 100
    cout << "b: " << b << endl;  // 100
    cout << "c: " << c << endl;  // 100
    cout << "d: " << d << endl;  // 100

    cout << endl;

    a = 200;

    cout << "a: " << a << endl;  // 200
    cout << "b: " << b << endl;  // 200
    cout << "c: " << c << endl;  // 200
    cout << "d: " << d << endl;  // 100

    cout << endl;

    b = 300;

    cout << "a: " << a << endl;  // 300
    cout << "b: " << b << endl;  // 300
    cout << "c: " << c << endl;  // 300
    cout << "d: " << d << endl;  // 100

    cout << endl;

    c = 400;

    cout << "a: " << a << endl;  // 400
    cout << "b: " << b << endl;  // 400
    cout << "c: " << c << endl;  // 400
    cout << "d: " << d << endl;  // 100

    cout << endl;

    d = 500;

    cout << "a: " << a << endl;  // 400
    cout << "b: " << b << endl;  // 400
    cout << "c: " << c << endl;  // 400
    cout << "d: " << d << endl;  // 500

    cout << endl;

    cout << "global: " << global << endl;

    int& x = fun1();     // analogous to int a = 10; int& b = a; int& x = b;

    cout << "x: " << x << endl;

    int y = fun1();      // analogous to int a = 10; int& b = a; int y = b;

    cout << "y: " << y << endl;

    // int& z = fun2();  // error: invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'

    cout << endl;

    global += 1;

    cout << "global: " << global << endl;

    cout << "x: " << x << endl;

    cout << "y: " << y << endl;

    cout << endl;

    int& g = fun3(a);

    // int& h = fun4(a);  // warning: reference to local variable 'temp' returned [-Wreturn-local-addr]

    cout << "a: " << a << endl;

    cout << "g: " << g << endl;

    // cout << "h: " << h << endl;

    g = 600;

    cout << "a: " << a << endl;

    cout << "g: " << g << endl;

    cout << endl;

    return 0;
}
