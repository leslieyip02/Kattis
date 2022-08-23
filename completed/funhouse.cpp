#include <iostream>
#include <utility>
using namespace std;

int main()
{
    const pair<int, int> UP { 0, -1 };
    const pair<int, int> DOWN { 0, 1 };
    const pair<int, int> LEFT { -1, 0 };
    const pair<int, int> RIGHT { 1, 0 };

    int w, l, x, y;
    int h = 1;

    pair<int, int> dir;

    cin >> w >> l;
    while (!(w == 0 && l == 0))
    {
        string rm[l];
        for (int i = 0; i < l; i++)
            cin >> rm[i];

        x = 0;
        y = 0;
        for (int i = 1; i < w - 1; i++)
        {
            if (rm[0][i] == '*')
            {
                dir = DOWN;
                x = i;
                break;
            }
            else if (rm[l - 1][i] == '*')
            {
                dir = UP;
                x = i;
                y = l - 1;
                break;
            }
        }

        if (x == 0)
        {
            for (int i = 1; i < l - 1; i++)
            {
                if (rm[i][0] == '*')
                {
                    dir = RIGHT;
                    y = i;
                    break;
                }
                else if (rm[i][w - 1] == '*')
                {
                    dir = LEFT;
                    x = w - 1;
                    y = i;
                    break;
                }
            }
        }

        while (true)
        {
            x += dir.first;            
            y += dir.second;            

            if (rm[y][x] == 'x')
            {
                rm[y][x] = '&';
                break;
            }

            if (rm[y][x] == '/')
            {
                if (dir == UP)
                    dir = RIGHT;
                else if (dir == DOWN)
                    dir = LEFT;
                else if (dir == LEFT)
                    dir = DOWN;
                else
                    dir = UP;
            }

            if (rm[y][x] == '\\')
            {
                if (dir == UP)
                    dir = LEFT;
                else if (dir == DOWN)
                    dir = RIGHT;
                else if (dir == LEFT)
                    dir = UP;
                else
                    dir = DOWN;
            }
        }        

        cout << "HOUSE " << h++ << endl;
        for (int i = 0; i < l; i++)
            cout << rm[i] << endl;

        cin >> w >> l;
    }
}
