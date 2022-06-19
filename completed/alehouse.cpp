#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int orderByEntry(const void *a, const void *b)
{
    const int *lhs = static_cast<int const*>(a);
    const int *rhs = static_cast<int const*>(b);

    // compare time
    if (lhs[0] > rhs[0])
        return 1;
    else if (lhs[0] < rhs[0])
        return -1;
    // compare entry or exit
    else
        return (lhs[1] < rhs[1] ? 1 : -1);
}

int main()
{
    int n, k;
    cin >> n >> k;

    // store 1 array each for in and out
    int io[n * 2][2];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        // offset exit time
        io[i * 2][0] = a;
        io[i * 2 + 1][0] = b + k;
        
        // +1 to total on entry and -1 on exit 
        io[i * 2][1] = 1;
        io[i * 2 + 1][1] = -1;
    }

    // sort in ascending time order
    // sort entry before exit
    qsort(io, n * 2, sizeof(int[2]), orderByEntry);

    // simulate the entire week and track ins and outs
    int friends = 0;
    int currentlyInside = 0;
    for (int i = 0; i < n * 2; i++)
    {
        currentlyInside += io[i][1];
        friends = max(currentlyInside, friends);
    }
    
    cout << friends << endl;

    return 0;
}