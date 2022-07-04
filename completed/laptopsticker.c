#include <stdio.h>

int main(void)
{
    int wc, hc, ws, hs;
    scanf("%i %i %i %i", &wc, &hc, &ws, &hs);

    printf("%i", wc >= ws + 2 && hc >= hs + 2);

    return 0;
}