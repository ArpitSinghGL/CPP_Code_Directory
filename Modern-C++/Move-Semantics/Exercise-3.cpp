#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

class Integer
{
    private:

    int value;

    public:

    Integer(int value) : value(value)
    {
        cout << "Parameterized constructor is invoked...." << endl;
    }

    // Copy-Constructor
    Integer(const Integer& integerObject)
    {
        cout << "Copy-Constructor is invoked...." << endl;
        this -> value = integerObject.value;
    }

    // Copy-Assignment operator
    void operator = (const Integer& integerObject)
    {
        cout << "Copy-Assignment operator is invoked...." << endl;
        this -> value = integerObject.value;
    }

};

int main()
{

    return 0;
}