#include <stdio.h>
#include <stdbool.h>

int r, c, tx, ty;
int f[50][50] = { 0 };
int o[4][2] = { { 1, 0 }, { -1, 0 },  { 0, 1 }, { 0, -1 } };

// flood adjacent tiles to the value of a
void flood(int x0, int y0, int a)
{
    int x1, y1;
    for (int i = 0; i < 4; i++)
    {
        x1 = x0 + o[i][0];
        y1 = y0 + o[i][1];

        if (x1 == tx && y1 == ty && a < 0)
            continue;

        if (x1 >= 0 && x1 < c &&
            y1 >= 0 && y1 < r)
        {
            if (f[y1][x1] == 0 || (a < 0 && f[y1][x1] > 0))
                f[y1][x1] = a;
        }
    }
}

int main()
{
    scanf("%i %i", &r, &c);

    char t[c + 1];
    for (int i = 0; i < r; i++)
    {
        scanf("%s", t);
        for (int j = 0; j < c; j++)
        {
            if (t[j] == 'D')
            {
                tx = j;
                ty = i;
            }
            
            if (t[j] == 'S')
                f[i][j] = 1;
            else if (t[j] == '*')
                f[i][j] = -1;
            else if (t[j] == 'X')
                f[i][j] = -__INT_MAX__;
        }
    }

    int d = 1;
    bool alive = false;
    while (f[ty][tx] == 0)
    {
        alive = false;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (f[i][j] == d)
                {
                    alive = true;
                    flood(j, i, d + 1);
                }
            }
        }

        if (!alive)
            break;            

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {   
                if (f[i][j] == -d)
                    flood(j, i, -(d + 1));
            }
        }

        d++;
    }

    if (alive)
        printf("%i\n", f[ty][tx] - 1);
    else
        printf("KAKTUS\n");

    return 0;
}