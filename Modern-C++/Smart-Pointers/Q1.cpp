#include <bits/stdc++.h>

using namespace std;

class Resource
{
    public:

    int* arr = new int[10];

    int a = 10;

    double d = 12.134;

    string str = "Oliver Queen";
    
};

unique_ptr<Resource> transfer_ownership(unique_ptr<Resource> ptr)
{
    return ptr;
}

unique_ptr<Resource> create_unique_ptr()
{
    return make_unique <Resource> ();
}

int main()
{
    unique_ptr<Resource> ptr_to_resource = create_unique_ptr();

    cout << ptr_to_resource -> a << endl;

    unique_ptr<Resource> another_ptr_to_resource = std::move(ptr_to_resource);

    cout << another_ptr_to_resource -> d << endl;
    cout << another_ptr_to_resource -> str << endl;

    ptr_to_resource = transfer_ownership(std::move(another_ptr_to_resource));

    cout << ptr_to_resource -> str << endl;
    cout << ptr_to_resource -> d << endl;
    cout << ptr_to_resource -> a << endl;
 
    return 0;
}