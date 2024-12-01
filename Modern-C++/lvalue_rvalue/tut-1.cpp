#include <iostream>
#include <string.h>

using namespace std;

// setValue1() takes a non-constant lvalue reference which can accept an lvalue only and not rvalue
void setValue1(int& val)
{
    return;
}

// setValue2() takes a constant lvalue reference which can accept both lvalue and rvalue
void setValue2(const int& val)
{
    return;
}

// printName1() takes a non-constant lvalue reference which can accept only an lvalue
void printName1(string& name)
{
    cout << name << endl;
}

// printName2() takes a constant lvalue reference which can accept both lvalue and rvalue
void printName2(const string& name)
{
    cout << name << endl;
}

// printName3() takes a rvalue reference which can only accept an rvalue
void printName3(string&& name)
{
    cout << name << endl;
}

// int& getValue()
// {
//     return 10;
// }

int main()
{
    int a = 10;   // Here a is the lvalue and 10 is the rvalue.

    // Note:

    // 10 is an rvalue because it does not have any memory associated with it as it is just a literal value that is present inside a
    // memory location that is alloted to a.

    // a is an lvalue because it has a memory location associated with it.

    // a is like a container that contains the value 10.

    // So, basically, the container is refered to as the lvalue and the actual value is refered to as the rvalue.

    // 10 = a;   // error: lvalue required as left operand of assignment.

    int b = a;    // Here b is an lvalue and a is an rvalue.

    int& c = a;   // Here c is an lvalue and a is also an lvalue.

    // int& d = 10;   // error: invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'.

    // In the above case, int& is an lvalue reference and 10 is an rvalue


    // Calling setValue with an lvalue

    int i = 100;

    setValue1(i);   // We can have an lvalue reference to an lvalue

    // Calling setValue with an rvalue

    // setValue(100); // error: invalid initialization of non-const reference of type 'int&' from an rvalue of type 'int'

    // We cannot have an non-constant lvalue reference to an rvalue

    const int& num = 10;   // This is valid as it is a const lvalue reference to an rvalue

    // We can have a constant lvalue reference to both lvalue and rvalue as shown below:
    setValue2(i);

    setValue2(100);


    // Let's look at the following string examples

    string firstName = "Oliver";   // lvalue = firstName and rvalue = "Oliver"

    string lastName = " Queen";    // lvalue = lastName and rvalue = " Queen"

    string fullName = firstName + lastName;   // lvalue = fullName and rvalue = firstName + lastName

    printName1(firstName);

    printName1(lastName);

    printName1(fullName);

    // printName1(firstName + lastName);
    // error: invalid initialization of non-const reference of type 'std::__cxx11::string& {aka std::__cxx11::basic_string<char>&}' 
    // from an rvalue of type 'std::__cxx11::basic_string<char>'

    printName2(firstName);

    printName2(lastName);

    printName2(fullName);

    printName2(firstName + lastName);

    // Now let's talk about an rvalue reference

    // printName3(fullName);  // Note that fullName is an lvalue and printName3 can only accept an rvalue
    // An rvalue reference cannot be bound to an lvalue

    printName3(firstName + lastName);   // Note that the expression firstName + lastName results in an rvalue



    return 0;
}
