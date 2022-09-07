#include <stdio.h>

int main(void)
{
    int x, n, l, u;
    double y, f;
    scanf("%i %lf %i", &x, &y, &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%i %i %lf", &l, &u, &f);        
        y += (f - 1) * (u - l);
    }

    printf("%0.10lf\n", x / y);

    return 0;
}