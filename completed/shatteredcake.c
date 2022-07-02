#include <stdio.h>

int main(void)
{
    int w, n, w1, l1;
    scanf("%i\n%i", &w, &n);

    int a = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%i %i", &w1, &l1);
        a += w1 * l1;
    }

    printf("%i", a / w);
    return 0;
}