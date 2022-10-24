#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%i %i", &n, &m);

    printf("%i\n", m % n ? 1 : 0);

    return 0;
}
