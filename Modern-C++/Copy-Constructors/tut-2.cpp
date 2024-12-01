#include <iostream>

using namespace std;

class Array
{
    public:

    Array()
    {
        cout << "Default constructor is called...." << endl;

        data = new int[10];

        for(int i = 0 ; i < 10 ; i++)
        {
            data[i] = i * i;
        }

    }

    void printData()
    {
        for(int i = 0 ; i < 10 ; i++)
        {
            cout << data[i] << endl;
        }
    }

    void setData(int index , int value)
    {
        data[index] = value;
    }

    ~Array()
    {
        cout << "Destructor is called...." << endl;
        delete[] data;
    }

    private:

    int* data;
};

int main()
{
    cout << endl;

    Array arr1;
    arr1.printData();

    arr1.setData(0 , 10000);

    cout << endl;

    Array arr2 = arr1;

    arr2.printData();

    cout << endl;

    // Demonstrating shallow copy

    arr2.setData(1 , 20000);

    arr1.printData();

    cout << endl;

    arr2.printData();

    cout << endl;

    // Note that C++ provides us a free/default copy-constructor and a copy-assignment opearator.
    // The default copy-constructor and the default copy-assignment operator perform a "shallow-copy".

    // In order to create a "deep-copy" , we need to define our own copy-constructor and copy-assignment operator.

    return 0;
}
