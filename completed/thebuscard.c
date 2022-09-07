#include <stdio.h>

int main(void)
{
    int k;
    scanf("%i", &k);

    int c = k / 500;
    k %= 500;
    if (k > 0)
        c += (k > 400 || k <= 200 ? 1 : 2);

    printf("%i\n", c);

    return 0;
}