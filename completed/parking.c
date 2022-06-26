#include <stdio.h>

int main(void)
{
    int t, n;
    scanf("%i", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%i", &n);

        int p;
        int max = 0;
        int min = 100;

        for (int j = 0; j < n; j++)
        {
            scanf("%i", &p);
            max = p > max ? p : max;
            min = p < min ? p : min;
        }

        printf("%i\n", (max - min) * 2);
    }

    return 0;
}