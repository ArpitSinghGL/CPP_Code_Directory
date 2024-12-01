#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    if(int x = min(10 , 20) ; x == 10)
    {
        cout << "Looks good !" << endl;
    }
    else
    {
        cout << "This does not look good !" << endl;
    }
    return 0;
}