#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, na, nb;
    cin >> t;
    while (t--)
    {        
        cin >> na;
        int a[na + 1];
        for (int i = 0; i <= na; i++)
            cin >> a[i];

        cin >> nb;
        int b[nb + 1];
        int c[na + nb + 1] = { 0 };
        for (int j = 0; j <= nb; j++)
        {
            cin >> b[j];
            for (int i = 0; i <= na; i++)
                c[i + j] += a[i] * b[j];
        }
        
        cout << na + nb << '\n';
        for (int i = 0; i < na + nb + 1; i++)
            cout << c[i] << ' ';
        cout << '\n';
    }

    return 0;
}