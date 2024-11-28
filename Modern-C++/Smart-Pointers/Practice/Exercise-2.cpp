#include <bits/stdc++.h>

using namespace std;

class Resource
{
    private:

    int id;

    public:

    Resource(int id)
    {
        this -> id = id;
    }

    int getId()
    {
        return this -> id;
    }
};

class ReferenceCounter
{
    public:

    shared_ptr<Resource> shrd_ptr;

    ~ReferenceCounter()
    {
        cout << "Destructor is invoked !" << endl;
    }
};

int main()
{
    // Dynamically allocated object
    shared_ptr<Resource> resource = make_shared<Resource>(10);

    // Multiple instances of ReferenceCounter class
    ReferenceCounter refCounter1 , refCounter2;

    // Multiple instances of ReferenceCounter class sharing the ownership of the same resource
    refCounter1.shrd_ptr = resource;
    refCounter2.shrd_ptr = resource;

    cout << resource.use_count() << endl;

    refCounter1.shrd_ptr.reset();

    cout << resource.use_count() << endl;

    refCounter2.shrd_ptr.reset();

    cout << resource.use_count() << endl;

    
    return 0;
}