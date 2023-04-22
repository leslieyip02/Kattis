#include <iostream>
using namespace std;

int main()
{
    int N, S, R;
    cin >> N >> S >> R;

    int t[10] = {0};
    int s, r;

    while (S--)
    {
        cin >> s;
        t[s - 1]--;
    }

    while (R--)
    {
        cin >> r;
        t[r - 1]++;
    }

    for (int i = 0; i < N; i++)
    {
        if (t[i] == 1)
        {
            if (i > 0)
            {
                if (t[i - 1] == -1)
                {
                    t[i - 1] = 0;
                    t[i] = 0;
                }
            }

            if (t[i] == 1 && i < N)
            {
                if (t[i + 1] == -1)
                {
                    t[i + 1] = 0;
                    t[i] = 0;
                }
            }
        }
    }

    int n = 0;
    for (int i = 0; i < N; i++)
    {
        if (t[i] == -1)
        {
            n++;
        }
    }

    cout << n << '\n';

    return 0;
}