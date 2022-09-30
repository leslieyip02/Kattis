#include <stdio.h>

int main(void)
{
    int n, c;
    scanf("%i", &n);

    c = 1;
    while (n > 0)
    {
        if (n & 1)
            c <<= 1;
        n >>= 1;
    }

    printf("%i\n", c);

    return 0;
}