#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    float a, b, c;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%f %f %f", &a, &b, &c);
        if (a + b == c ||
            abs(a - b) == c ||
            a * b == c ||
            a / b == c ||
            b / a == c)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }

    return 0;
}