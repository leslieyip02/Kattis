#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sort(p, p + n, greater<int>());

    int c = 0;
    for (int i = 0; i < n / 2; i++)
        c += p[i];

    for (int i = n / 2; i < n; i++)
        c += (p[i] - 1) / 2;

    cout << c << '\n';

    return 0;
}
