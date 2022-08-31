#include <stdio.h>

int main(void)
{
    int v[8] = { 0 };
    int p[8] = { 2, 3, 5, 7, 11, 13, 17, 19 };
    for (int i = 0; i < 8; i++)
        scanf("%i", &v[i]);

    int n = 0;
    int r = 1;
    for (int i = 0; i < 8; i++)
    {
        n += (p[i] - v[i] - 1) * r;
        r *= p[i];
    }
   
    printf("%i\n", n);

    return 0;
}