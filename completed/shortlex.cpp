#include <iostream>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    ll i;
    cin >> T;
    while (T--)
    {
        cin >> i;

        ll j = 1;
        int k = 0;
        while (i >= j)
        {
            i -= j;
            j <<= 1;
            k++;
        }

        while (k--)
        {
            cout << ((i & ((ll) 1 << k)) != 0);
        }
        cout << '\n';
    }

    return 0;
}