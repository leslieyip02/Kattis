#include <stdio.h>

int main(void)
{
    int d;
    scanf("%i", &d);

    int t[d];
    for (int i = 0; i < d; i++)
        scanf("%i", &t[i]);

    int p, q, s;
    p = 50;
    for (int i = 0; i < d - 2; i++)
    {
        q = t[i] > t[i + 2] ? t[i] : t[i + 2];
        if (q < p)
        {
            p = q;
            s = i + 1;
        }
    }

    printf("%i %i\n", s, p);

    return 0;
}