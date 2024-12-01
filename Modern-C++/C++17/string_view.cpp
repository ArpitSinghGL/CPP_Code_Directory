#include <iostream>

using namespace std;

static int num_of_allocations_in_heap_memory = 0;

void* operator new (size_t size)
{
    num_of_allocations_in_heap_memory += 1;
    cout << "Allocated size: " << size << endl;
    return malloc(size);
}

void operator delete(void* ptr)
{
    cout << "Deallocated memory from heap !" << endl;
    free(ptr);
}

int main()
{
    string str1 { "My name is Oliver Queen" };

    string_view str2 { str1 };

    string_view str3 (str1);

    string_view str4 = str1;

    cout << "str1: " << str1 << endl;

    cout << "str2: " << str2 << endl;

    cout << "str3: " << str3 << endl;

    cout << "str4: " << str4 << endl;

    return 0;
}