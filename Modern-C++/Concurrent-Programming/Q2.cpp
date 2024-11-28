#include <bits/stdc++.h>

#include <threads.h>

#include <mutex>

using namespace std;

int sum = 0;

void computeSum(vector<int>& v)
{
    for(auto it : v)
    {
        sum += it;
    }
    return;
}

int main()
{
    vector<int> v = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};

    thread thread1(computeSum , ref(v));

    thread1.join();

    cout << "The sum of all elements of the vector is: " << sum << endl;

    return 0;
}