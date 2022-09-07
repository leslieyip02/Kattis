#include <stdio.h>

int main(void)
{
    int n, b, x;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i", &b);

        for (x = 0; x < 256; x++)
        {
            if ((x ^ (unsigned char) (x << 1)) == b)
            {
                printf("%i ", x);
                break;
            }
        }
    }

    printf("\n");

    return 0;
}