#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, s, i, j, k;
    cin >> n;

    vector<string> w(n);
    size_t m = 0;
    for (i = 0; i < n; i++)
    {
        cin >> w[i];
        m = max(w[i].length(), m);
    }

    for (i = 0; i < m; i++)
    {
        s = 0;
        k = 0;
        for (j = 0; j < n; j++)
        {
            if (i < w[j].length())
            {
                s += (int) w[j][i];
                k++;
            }
        }

        s /= k;
        cout << (char) s;
    }

    return 0;
}