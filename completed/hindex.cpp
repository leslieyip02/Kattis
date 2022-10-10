#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    int c[n];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    // elements are sorted descending
    // so index of each element + 1 = number of elements greater than itself
    sort(c, c + n, greater<int>());

    int m = 0;
    for (int h = 0; h < n; h++)
        if (c[h] > h)
            m = h + 1;

    cout << m << '\n';

    return 0;
}