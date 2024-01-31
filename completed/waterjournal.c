#include <stdio.h>

int main()
{
    int n, a, b, w;
    scanf("%i %i %i", &n, &a, &b);
    int min = 0;
    int max = 0;
    while (--n)
    {
        scanf("%i", &w);
        if (w == a)
        {
            min = 1;
        }
        if (w == b)
        {
            max = 1;
        }
    }
    if (!min && !max)
    {
        printf("-1\n");
    }
    else if (min && max)
    {
        while (a <= b)
        {
            printf("%i\n", a);
            a++;
        }
    }
    else
    {
        printf("%i\n", min ? b : a);
    }
    return 0;
}