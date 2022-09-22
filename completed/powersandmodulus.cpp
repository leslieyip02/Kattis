#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unsigned long long a, b, n, m;
    cin >> a >> b;

    n = 1;
    m = a;  
    a = (a * (a + 1) / 2) % m;

    // right-to-left binary modular exponentiation
    while (b > 0)
    {
        n = (n * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }

    cout << n << '\n';

    return 0;
}
