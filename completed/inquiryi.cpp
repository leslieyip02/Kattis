#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long n, p, q, r, s;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    q = 0; // q is the sum from k + 1
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i] * a[i];
        q += a[i];
    }
    
    p = b[0]; // p is the sum of squares until k
    q -= a[0];
    r = p * q;
    s = r;
    for (int i = 1; i < n - 1; i++)
    {
        r -= p * a[i];
        p += b[i];
        q -= a[i];
        r += b[i] * q;

        if (r > s)
        {
            s = r;
        }
    }

    cout << s << '\n';

    return 0;
}