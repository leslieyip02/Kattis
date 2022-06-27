#include <stdio.h>

int main(void)
{
    unsigned int n;
    scanf("%i", &n);

    unsigned int u = 0;
    while (n > 0)
    {
        u <<= 1;
        if (n & 1 == 1)
            u ^= 1;
        n >>= 1;
    }

    printf("%i", u);
    return 0;
}