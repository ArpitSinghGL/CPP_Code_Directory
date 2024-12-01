#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int x = 15;

    cout << clamp(x , 10 , 20) << endl;

    return 0;
}