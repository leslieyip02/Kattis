#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int b[6];
    int h1, h2;
    for (int i = 0; i < 6; i++)
    {
        cin >> b[i];
    }
    cin >> h1 >> h2;

    int t1[3];
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            for (int k = j + 1; k < 6; k++)
            {
                if (b[i] + b[j] + b[k] == h1)
                {
                    t1[0] = b[i];
                    t1[1] = b[j];
                    t1[2] = b[k];
                    goto ok;
                }
            }

        }
    }

ok:
    int n = sizeof(t1) / sizeof(*t1);
    sort(t1, t1 + n);
    for (int i = 2; i >= 0; i--)
    {
        cout << t1[i] << ' ';
    }

    int i = 0;
    int t2[3];
    for (int j = 0; j < 6; j++)
    {
        if (find(t1, t1 + n, b[j]) == t1 + n)
        {
            t2[i++] = b[j];
        }
    }
    sort(t2, t2 + n);
    for (int i = 2; i >= 0; i--)
    {
        cout << t2[i] << ' ';
    }
    cout << endl;
    return 0;
}
