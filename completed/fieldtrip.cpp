#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int s = 0;
    vector<int> c(N);
    for (int i = 0; i < N; i++)
    {
        cin >> c[i];
        s += c[i];
    }

    bool ok = s % 3 == 0;
    int i, j, k;
    if (ok)
    {
        int p = s / 3;

        i = 0;
        k = 0;
        while (k < p && i < N)
        {
            k += c[i];
            i++;
        }
        ok &= k == p;

        j = i;
        k = 0;
        while (k < p && j < N)
        {
            k += c[j];
            j++;
        }
        ok &= k == p;
    }

    if (ok)
    {
        cout << i << ' ' << j << '\n';
    }
    else
    {
        cout << "-1\n";
    }
    return 0;
}
