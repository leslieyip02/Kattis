#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string msg;
        cin >> msg;

        int m = msg.length();
        int k = (int) sqrt(m);
        while (pow(k, 2) != m)
        {
            m++;
            k = (int) sqrt(m);
        }

        while (msg.length() < m)
            msg += '*';

        char tbl[k][k];
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                tbl[i][j] = msg[i * k + j];

        for (int i = 0; i < k; i++)
            for (int j = k - 1; j > -1; j--)
                if (tbl[j][i] != '*')
                    cout << tbl[j][i];
        cout << endl;
    }

    return 0;
}