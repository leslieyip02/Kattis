#include <stdio.h>

int main(void)
{
    int n, a;

    int x = 1;
    while (scanf("%i", &n) != EOF)
    {
        int p = 1000001;
        int q = -1000001;
        for (int i = 0; i < n; i++)
        {
            scanf("%i", &a);

            if (a < p)
                p = a;

            if (a > q)
                q = a;
        }

        printf("Case %i: %i %i %i\n", x, p, q, q - p);
        x++;
    }

    return 0;
}