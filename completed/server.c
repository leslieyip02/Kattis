#include <stdio.h>

int main(void)
{
    int n, t, x;
    scanf("%i %i", &n, &t);

    int i = 0;
    while (i < n)
    {
        scanf("%i", &x);
        if ((t -= x) >= 0)
            i++;
        else
            break;
    }

    printf("%i", i);

    return 0;
}