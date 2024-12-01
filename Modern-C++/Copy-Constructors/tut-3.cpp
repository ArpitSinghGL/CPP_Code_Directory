#include <iostream>

using namespace std;

class Array
{
    public:

    Array() : size(10)
    {
        cout << "Default constructor is called...." << endl;

        data = new int[size];

        for(int i = 0 ; i < size ; i++)
        {
            data[i] = i * i;
        }

    }

    Array(int size) : size(size) 
    {
        cout << "Parameterized constructor is invoked..." << endl;

        (this -> data) = new int[size];

        for(int i = 0 ; i < size ; i++)
        {
            (this -> data)[i] = i * i;
        }
    }

    // Creating our own Copy-Constructor (for deep-copy)
    Array(const Array& arrayObject)
    {
        cout << "User-defined deep-copy copy-constructor is invoked..." << endl;
        this -> size = arrayObject.size;
        this -> data = new int[this -> size];
        for(int i = 0 ; i < this -> size ; i++)
        {
            (this -> data)[i] = arrayObject.data[i];
        }
    }

    // Creating our own Copy-Assignment operator (for deep-copy)
    void operator = (const Array& arrayObject)
    {
        cout << "User-defined Copy-Assignment operator for deep copy is invoked..." << endl;
        delete[] (this -> data);
        this -> size = arrayObject.size;
        this -> data = new int[this -> size];
        for(int i = 0 ; i < this -> size ; i++)
        {
            (this -> data)[i] = arrayObject.data[i];
        }
    }

    void printData()
    {
        for(int i = 0 ; i < size ; i++)
        {
            cout << data[i] << endl;
        }
    }

    void setData(int index , int value)
    {
        data[index] = value;
    }

    int getSize()
    {
        return this -> size;
    }

    ~Array()
    {
        cout << "Destructor is called...." << endl;
        delete[] data;
    }

    private:

    int* data;

    int size;
};

int main()
{
    cout << endl;

    Array arr1;

    cout << "arr1.printData(): " << endl;
    arr1.printData();

    arr1.setData(0 , 10000);

    cout << endl;

    Array arr2(arr1);

    cout << "arr2.printData(): " << endl;
    arr2.printData();

    cout << endl;

    // Demonstrating deep-copy

    arr2.setData(1 , 20000);

    cout << "arr1.printData(): " << endl;
    arr1.printData();

    cout << endl;

    cout << "arr2.printData(): " << endl;
    arr2.printData();

    cout << endl;

    // Note that C++ provides us a free/default copy-constructor and a copy-assignment opearator.
    // The default copy-constructor and the default copy-assignment operator perform a "shallow-copy".

    // In order to create a "deep-copy" , we need to define our own copy-constructor and copy-assignment operator.

    Array arr3(20);

    cout << "arr3.getSize(): " << arr3.getSize() << endl;

    cout << "arr3.printData(): " << endl;
    arr3.printData();

    cout << endl;

    arr3 = arr1;

    cout << "arr3.getSize(): " << arr3.getSize() << endl;

    cout << "arr3.printData(): " << endl;
    arr3.printData();

    cout << endl;

    arr3.setData(3 , 50000);

    cout << "arr3.printData(): " << endl;
    arr3.printData();

    cout << endl;

    cout << "arr1.printData(): " << endl;
    arr1.printData();

    cout << endl;

    return 0;
}
