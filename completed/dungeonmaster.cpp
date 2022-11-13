#include <iostream>
using namespace std;

int dirs[6][3] = {{ 1, 0, 0 }, { -1, 0, 0 },
    { 0, 1, 0 }, { 0, -1, 0 }, { 0, 0, 1 }, { 0, 0, -1 }};

int main()
{
    int l, r, c;
    cin >> l >> r >> c;

    while (l != 0 || r != 0 || c != 0)
    {
        int maze[l][r][c];

        string row;
        int tx, ty, tz;
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                cin >> row;
                for (int k = 0; k < c; k++)
                {
                    if (row[k] == 'S')
                        maze[i][j][k] = 1;

                    if (row[k] == '.')
                        maze[i][j][k] = 0;

                    if (row[k] == '#')
                        maze[i][j][k] = -1;

                    if (row[k] == 'E')
                    {
                        tx = k;
                        ty = j;
                        tz = i;

                        maze[i][j][k] = 0;
                    }
                }
            }
        }

        int m = 1;
        bool changed = true;
        while (changed)
        {
            changed = false;
            for (int i = 0; i < l; i++)
            {
                for (int j = 0; j < r; j++)
                {
                    for (int k = 0; k < c; k++)
                    {
                        if (maze[i][j][k] == m)
                        {
                            for (auto dir : dirs)
                            {
                                int x = k + dir[2];
                                int y = j + dir[1];
                                int z = i + dir[0];

                                if (0 <= x && x < c &&
                                    0 <= y && y < r &&
                                    0 <= z && z < l &&
                                    maze[z][y][x] == 0)
                                {
                                    maze[z][y][x] = m + 1;
                                    changed = true;
                                }
                            }
                        }
                    }
                }
            }

            if (maze[tz][ty][tx] != 0)
                break;

            m++;
        }

        if (maze[tz][ty][tx] != 0)
            cout << "Escaped in " << m << " minute(s).\n";
        else
            cout << "Trapped!\n";

        cin >> l >> r >> c;
    }
}
