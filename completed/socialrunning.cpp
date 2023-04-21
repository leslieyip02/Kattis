#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    int y = 100000;
    for (int i = 0; i < n; i++)
    {
        int x = d[i] + d[(i - 2 + n) % n];
        if (x < y)
        {
            y = x;
        }
    }

    cout << y << '\n';

    return 0;
}