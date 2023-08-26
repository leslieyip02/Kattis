#include <iostream>
using namespace std;

int main()
{
    char c;
    int g[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> c;
            if (c == 'X')
            {
                g[i][j] = 1;
            }
            else if (c == 'O')
            {
                g[i][j] = -1;
            }
        }
    }

    int w = 0;
    for (int i = 0; i < 3; i++)
    {
        if (g[i][0] == g[i][1] && g[i][0] == g[i][2])
        {
            w = g[i][0];
        }
        else if (g[0][i] == g[1][i] && g[0][i] == g[2][i])
        {
            w = g[0][i];
        }
    }
    if (g[0][0] == g[1][1] && g[0][0] == g[2][2])
    {
        w = g[0][0];
    }
    else if (g[2][0] == g[1][1] && g[2][0] == g[0][2])
    {
        w = g[2][0];
    }

    if (w == 0)
    {
        cout << "ingen har vunnit\n";
    }
    else if (w == 1)
    {
        cout << "Johan har vunnit\n";
    }
    else
    {
        cout << "Abdullah har vunnit\n";
    }
}
