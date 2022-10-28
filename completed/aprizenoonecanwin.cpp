#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, x, i;
    cin >> n >> x;

    int y[n];
    for (i = 0; i < n; i++)
        cin >> y[i];

    sort(y, y + n);

    i = 1;
    while (i < n && y[i] + y[i - 1] <= x)
        i++;

    cout << i << '\n';

    return 0;
}