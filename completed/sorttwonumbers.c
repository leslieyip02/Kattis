#include <stdio.h>

int main(void)
{
    int a, b;
    scanf("%i", &a);
    scanf("%i", &b);
    printf("%i %i", (a > b ? b : a), (a > b ? a : b));
    return 0;
}