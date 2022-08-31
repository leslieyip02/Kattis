#include <stdio.h>
#include <string.h>

int s[8][2] = { { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 },
    { 2, 0 }, { 0, 2 }, { -2, 0 }, { 0, -2 } };

int main(void)
{
    char f[16];
    scanf("%s", f);

    int n = strlen(f) * 4 + 1;
    char d[5][n];
    memset(d, '.', 5 * n * sizeof(char));

    for (int i = 0; i < strlen(f); i++)
    {
        int x = i * 4 + 2;
        int y = 2;
        d[y][x] = f[i];

        char c = i % 3 == 2 ? '*' : '#';
        for (int j = 0; j < 8; j++)
            if (d[y + s[j][1]][x + s[j][0]] == '#' ||
                d[y + s[j][1]][x + s[j][0]] == '.')
                d[y + s[j][1]][x + s[j][0]] = c;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%c", d[i][j]);
        printf("\n");
    }

    return 0;
}