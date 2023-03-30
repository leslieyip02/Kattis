#include <stdio.h>

int main()
{
    int n;
    scanf("%i", &n);

    long a;
    long b = 0;
    long m = 1000000;
    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &a);
        if (a < m)
        {
            m = a;
        }

        b += a;
    }

    b += m * (n - 2);
    printf("%ld\n", b);

    return 0;
}