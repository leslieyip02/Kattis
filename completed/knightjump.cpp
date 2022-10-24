#include <iostream>
#include <utility>
using namespace std;

pair<int, int> dirs[8] = {{ 1, 2 }, { 2, 1 }, { 2, -1 }, { 1, -2 }, 
    { -1, -2 }, { -2, -1 }, { -2, 1 }, { -1, 2 }};

int main()
{
    int n;
    cin >> n;

    int b[n][n];
    for (int i = 0; i < n; i++)
    {
        string r;
        cin >> r;
        for (int j = 0; j < n; j++)
        {
            if (r[j] == '#')
                b[i][j] = -1;
            else if (r[j] == 'K')
                b[i][j] = 1;
            else
                b[i][j] = 0;
        }
    }

    int s = 1;
    bool moved = true;
    while (!b[0][0] && moved)
    {
        moved = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (b[i][j] == s)
                {
                    for (pair<int, int> d : dirs)
                    {
                        int x = j + d.second;
                        int y = i + d.first;

                        if (0 <= x && x < n &&
                            0 <= y && y < n &&
                            b[y][x] == 0)
                        {
                            b[y][x] = s + 1;
                            moved = true;
                        }
                    }
                }
            }
        }

        s++;
    }

    cout << b[0][0] - 1 << '\n';

    return 0;
}