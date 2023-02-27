#include <iostream>
using namespace std;

int main()
{
    int h, k, v, s;
    cin >> h >> k >> v >> s;

    int d = 0;
    while (h > 0)
    {
        v += s;
        v -= max(1, v / 10);

        if (v >= k)
        {
            h++;
        }

        if (0 < v && v < k)
        {
            h--;

            if (h == 0)
            {
                v = 0;
            }
        }

        if (v <= 0)
        {
            h = 0;
            v = 0;
        }

        d += v;
        if (s > 0)
        {
            s--;
        }
    }

    cout << d << '\n';

    return 0;
}