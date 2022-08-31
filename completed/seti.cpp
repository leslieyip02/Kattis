#include <iostream>
using namespace std;

int p;
// modular exponentiation 
int mod(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    int m = mod(a, b / 2);
    m = (m * m) % p;

    if (b & 1)
        m = (m * a) % p;

    return m;
}

int main()
{
    int N, n;
    string msg;

    cin >> N;
    while (N--)
    {
        cin >> p >> msg;
        n = msg.length();

        int f[n];
        for (int k = 0; k < n; k++)
            f[k] = msg[k] == '*' ? 0 : (int) msg[k] - 96;

        // vandermonde matrix
        int vm[n][n];
        for (int i = 0; i < n; i++)
        {
            vm[i][0] = 1;
            for (int j = 1; j < n; j++)
                vm[i][j] = (int) (vm[i][j - 1] * (i + 1)) % p;
        }

        // gaussian elimination
        for (int k = 0; k < n; k++)
        {
            for (int i = k + 1; i < n; i++)
            {
                int r = (mod(vm[k][k], p - 2) * vm[i][k]) % p;
                for (int j = k; j < n; j++)
                    vm[i][j] = (p + vm[i][j] - vm[k][j] * r % p) % p;
                f[i] = (p + f[i] - f[k] * r % p) % p;
            }
        }

        // backwards substitution
        int a[n] = { 0 };
        for (int i = n - 1; i > -1; i--)
        {
            int s = f[i];
            for (int j = n - 1; j > i; j--)
                s = (p + s - vm[i][j] * f[j] % p) % p;
            f[i] = s * mod(vm[i][i], p - 2) % p;
        }

        for (int i = 0; i < n; i++)
            cout << f[i] << ' ';
        cout << '\n';
    }    

    return 0;
}