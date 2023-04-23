#include <iostream>
#include <vector>
using namespace std;

int a[50];

int main()
{
    int n = 0;
    for (int i = 1; i < 50; i++)
    {
        n += i;
        a[i] = n;
    }

    int D, R, T;
    cin >> D >> R >> T;

    for (int i = 1; i < 50; i++)
    {
        int r = a[i] - a[3];
        if (r <= R)
        {
            int t = T + (R - r) + a[2];
            for (int j = 1; j < 50; j++)
            {
                if (a[j] == t && i - j == D)
                {
                    cout << R - r << '\n';
                    return 0;
                }
            }
        }
    }

    return 0;
}