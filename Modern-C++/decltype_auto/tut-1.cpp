#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int x = 10;

    cout << "x: " << x << endl;

    decltype(x) y = 20;   // decltype(x) = const int

    cout << "y: " << y << endl;

    auto z = x;   // auto = int

    cout << "z: " << z << endl;

    // x += 2;  // error: assignment of read-only variable 'y'

    // y += 2;  // error: assignment of read-only variable 'y'

    z += 2;

    cout << "z: " << z << endl;

    return 0;
}
