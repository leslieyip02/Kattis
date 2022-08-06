#include <stdio.h>

int main(void)
{
    int t, m, n, x, y;
    scanf("%i", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%i %i", &m, &n);
        for (int j = 0; j < n; j++)
            scanf("%i %i", &x, &y);
        printf("%i\n", m - 1);
    }

    return 0;
}