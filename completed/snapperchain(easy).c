#include <stdio.h>

int main(void)
{
    int t, n, k, x, y;
    scanf("%i", &t);

    for (x = 1; x <= t; x++)
    {
        scanf("%i %i", &n, &k);
        k %= (1 << n);

        for (; n > 0; n--, k >>= 1)
            if ((k & 1) == 0)
                break;

        printf("Case #%i: %s\n", x, n == 0 ? "ON" : "OFF");
    }

    return 0;
}