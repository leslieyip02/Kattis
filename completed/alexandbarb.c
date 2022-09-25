#include <stdio.h>

int main(void)
{
    int k, m, n;
    scanf("%i %i %i", &k, &m, &n);
    printf("%s\n", (k % (m + n) >= m) ? "Alex" : "Barb");

    return 0;
}
