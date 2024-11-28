#include <bits/stdc++.h>

using namespace std;

class Resource
{
    private:

    int a = 10;

    double d = 12.134;

    string str = "Oliver Queen";

    public:

    int geta()
    {
        return this -> a;
    }

    double getd()
    {
        return this -> d;
    }

    string getstr()
    {
        return this -> str;
    }
    
};

class ResourceManager
{
    public:
    
    unique_ptr<Resource> transfer_ownership(unique_ptr<Resource> from)
    {
        return from;
    }
    
    unique_ptr<Resource> create_resource()
    {
        return make_unique <Resource> ();
    }
};

int main()
{
    ResourceManager  resourceManager;

    unique_ptr<Resource> ptr_to_resource = resourceManager.create_resource();

    cout << ptr_to_resource -> geta() << endl;
    cout << ptr_to_resource -> getd() << endl;
    cout << ptr_to_resource -> getstr() << endl;

    cout << endl;

    unique_ptr<Resource> another_ptr_to_resource;
    another_ptr_to_resource = resourceManager.transfer_ownership( std::move(ptr_to_resource) );

    cout << another_ptr_to_resource -> getd() << endl;
    cout << another_ptr_to_resource -> getstr() << endl;
    cout << another_ptr_to_resource -> geta() << endl;
 
    return 0;
}