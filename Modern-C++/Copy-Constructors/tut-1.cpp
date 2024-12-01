#include <iostream>
#include <string>

using namespace std;

class Vector
{
    public:

    float x , y , z;

    // Default constructor
    Vector()
    {
        cout << "Default constructor called....." << endl;
        this -> x = 0.0f;
        this -> y = 0.0f;
        this -> z = 0.0f;
    }

};

int main()
{
    string name = "mike shah";
    cout << name << endl;

    cout << endl;

    Vector myVector;        // Default constructor is called
    myVector.x = 1.01f;
    myVector.y = 2.01f;
    myVector.z = 3.01f;

    cout << endl;

    Vector myVector1;      // Default constructor is called
    cout << myVector1.x << endl;
    cout << myVector1.y << endl;
    cout << myVector1.z << endl;

    cout << endl;

    Vector myVector2 = myVector;       // Default copy constructor is called
    cout << myVector2.x << endl;
    cout << myVector2.y << endl;
    cout << myVector2.z << endl;

    cout << endl;

    Vector myVector3;       // Default copy constructor is called
    myVector3 = myVector;   // Default copy-assignment operator is called

    return 0;
}
