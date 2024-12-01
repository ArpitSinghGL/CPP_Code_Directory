#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << endl;


    int a = 10;

    cout << "The value of a before move(a): " << a << endl;

    int b = move(a);

    cout << "The value of b after move(a): " << b << endl;

    cout << "The value of a after move(a) is: " << a << endl;



    cout << endl;



    string str1 = "Oliver Queen";

    cout << "The value of str1 before move(str1): " << str1 << endl;

    string str2 = move(str1);

    cout << "The value of str2 after move(str1): " << str2 << endl;

    cout << "The value of str1 after move(str1) is: " << str1 << endl;



    cout << endl;



    int* ptr1 = new int(100);

    cout << "ptr1: " << ptr1 << endl;

    cout << "*ptr1: " << *ptr1 << endl;

    int* ptr2 = move(ptr1);

    cout << "ptr1: " << ptr1 << endl;

    cout << "*ptr1: " << *ptr1 << endl;

    cout << "ptr2: " << ptr2 << endl;

    cout << "*ptr2: " << *ptr2 << endl;

    

    cout << endl;

    return 0;
}
