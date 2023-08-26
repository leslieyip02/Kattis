#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int R, C;
    cin >> R >> C;
    vector<string> g(R);
    for (int i = 0; i < R; i++)
    {
        cin >> g[i];
    }

    for (int i = 0; i < C; i++)
    {
        int a = 0;
        for (int j = 0; j < R; j++)
        {
            if (g[j][i] == '#')
            {
                for (; a > 0; a--)
                {
                    g[j - a][i] = 'a';
                }
            }
            else 
            {
                if (g[j][i] == 'a')
                {
                    a++;
                }
                g[j][i] = '.';
            }
        }
        for (; a > 0; a--)
        {
            g[R - a][i] = 'a';
        }
    }

    for (auto r : g) {
        cout << r << endl;
    }
    return 0;
}
