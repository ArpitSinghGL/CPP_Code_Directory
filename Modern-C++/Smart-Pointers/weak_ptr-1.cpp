#include <bits/stdc++.h>

using namespace std;

class Person
{
    private:

    string name;
    int age;

    public:

    Person(string name , int age)
    {
        this -> name = name;
        this -> age = age;
    }

};

int main()
{
    cout << endl;

    shared_ptr <Person> shared_person1( new Person("Oliver Queen" , 23) );

    // Printing the memory address owned by the shared_ptr object shared_person1
    cout << "shared_person1.get(): " << shared_person1.get() << endl;

    // Printing the reference count of the memory address:
    cout << "shared_person1.use_count(): " << shared_person1.use_count() << endl;

    cout << endl;

    // Note: When a shared_ptr object shares the ownership of the memory address it points to with another shared_ptr object,
    // then the reference count of that memory address increases as shown below:

    shared_ptr <Person> shared_person2 = shared_person1;

    // Printing the memory address owned by the shared_ptr object shared_person2
    cout << "shared_person2.get(): " << shared_person2.get() << endl;

    // Printing the reference count:
    cout << "shared_person2.use_count(): " << shared_person2.use_count() << endl;

    cout << endl;

    // Note: When a shared_ptr object shares the memory address with a weak_ptr object, then the reference count of that memory address
    // does not increase. This is because a weak_ptr object does not take the ownership of a memory address unlike a shared_ptr object.

    // A weak pointer is a smart pointer that does not take ownership of an object but act as an observer. 
    // In other words, it does not participate in reference counting to delete an object or extend its lifetime. 
    // Weak pointers are mainly used to break the circular dependency that shared pointers create.

    weak_ptr <Person> weak_person = shared_person1;

    // Printing the memory address referred by the weak_ptr object weak_person
    cout << "weak_person.lock(): " << weak_person.lock() << endl;

    // Printing the reference count:
    cout << "weak_person.use_count(): " << weak_person.use_count() << endl;

    // Note: weak_ptr_object.use_count() tells about how many shared_ptr objects own the resource.

    cout << endl;

    // Note that if a shared_ptr object is reset, then the reference count of the memory address it was pointing to reduces by one.
    shared_person2.reset();

    // Printing the reference count
    cout << "shared_person1.use_count(): " << shared_person1.use_count() << endl;
    cout << "shared_person2.use_count(): " << shared_person2.use_count() << endl;

    cout << endl;

    // Note that if a weak_ptr object is reset, then it does not change the reference count of the memory address it was pointing to.
    weak_person.reset();

    // Printing the reference count
    cout << "shared_person1.use_count(): " << shared_person1.use_count() << endl;
    cout << "shared_person2.use_count(): " << shared_person2.use_count() << endl;
    cout << "weak_person.use_count(): " << weak_person.use_count() << endl;
    // Note: weak_ptr_object.use_count() tells about how many shared_ptr objects own the resource.

    cout << endl;

    return 0;
}