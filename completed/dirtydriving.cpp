#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p;
    cin >> n >> p;
    
    int x[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];

    sort(x, x + n);
    
    int c = 0;
    for (int i = 0; i < n; i++)
        c = max(p * (i + 1) - x[i], c);

    cout << c + x[0] << '\n';

    return 0;
}