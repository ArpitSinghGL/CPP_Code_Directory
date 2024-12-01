#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a = 10;

    int* ptr = &a;

    decltype(a) b; 

    // decltype(*ptr) c;   // error: 'c' declared as reference but not initialized

    return 0;
}
