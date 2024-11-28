#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

struct UserDefinedType
{
    UserDefinedType(int a , int b , int c)
    {
        cout << "Constructor with 3 params called...." << endl;
    }

    UserDefinedType(initializer_list <int> data) : m_data(data) 
    {
        cout << "Initializer list constructor called...." << endl;
    }

    void printData()
    {
        for(auto& i : m_data)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    private:

    vector <int> m_data;
};

int main()
{
    cout << endl;

    int a = 10;
    int b(20);
    int c {30};

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;

    cout << endl;

    float d {3};
    int e = 3.14f;
    int f (3.14f);
    // int g {3.14f};   // error: narrowing conversion of '3.1400001e+0f' from 'float' to 'int' inside { } [-Wnarrowing]

    cout << "d: " << d << endl;
    cout << "e: " << e << endl;
    cout << "f: " << f << endl;
    // cout << "g: " << g << endl;

    cout << endl;

    UserDefinedType udt1 ( {1 , 2 , 3 } );
    udt1.printData();

    cout << endl;

    UserDefinedType udt2 {1 , 2 , 3 , 4};
    udt2.printData();

    cout << endl;

    UserDefinedType udt3 (1 , 2 , 3);
    udt3.printData();

    cout << endl;

    UserDefinedType udt4 (1.2f , 3.3f , 4.4f);
    udt4.printData();

    cout << endl;

    // UserDefinedType udt5 {1.2f , 2.3f , 3.4f};
    // error: narrowing conversion of '3.1400001e+0f' from 'float' to 'int' inside { } [-Wnarrowing]


    return 0;
}