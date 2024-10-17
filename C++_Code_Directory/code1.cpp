#include <iostream>
#include <vector>

using namespace std;

// Code for finding the nth fibonacci number without recursion.

int main()
{
    int n;

    cout << "Enter the value of n: " ;
    cin >> n;

    int previous = 1 , previous_to_previous = 0;

    for(int i = 2 ; i <= n ; i++)
    {
        int ith_fib_num = previous + previous_to_previous;
        previous_to_previous = previous;
        previous = ith_fib_num;
    }

    cout << "The nth fibonacci number is: " << previous << endl;

    return 0;
}