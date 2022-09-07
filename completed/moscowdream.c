#include <stdio.h>

int main(void)
{
    int a, b, c, n;
    scanf("%i %i %i %i", &a, &b, &c, &n);
    printf("%s\n", n >= 3 && a + b + c >= n && a && b && c ? "YES" : "NO");

    return 0;
}