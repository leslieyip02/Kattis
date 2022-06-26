#include <stdio.h>

int main(void)
{
    int n;
    scanf("%i", &n);

    int i = 1;
    int l = 0;
    while (n >= i * i)
    {
        n -= i * i;
        i += 2;
        l++;
    }

    printf("%i", l);

    return 0;
}