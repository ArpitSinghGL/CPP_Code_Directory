#include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr < int[] > shrd_ptr = make_shared < int[] > (5);

    for(int i = 0 ; i < 5 ; i++)
    {
        shrd_ptr[i] = i;
    }

    for(int i = 0 ; i < 5 ; i++)
    {
        cout << shrd_ptr[i] << " ";
    }

    cout << endl;

    return 0;
}