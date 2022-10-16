#include <stdio.h>

int main(void)
{
    long a, b, c, x, y, z;
    scanf("%ld %ld", &a, &b);

    while (a != 0 || b != 0)
    {
        c = 0;
        z = 0;
        while (a > 0 || b > 0)
        {
            x = a % 10;
            y = b % 10;

            a /= 10;
            b /= 10;

            if (x + y + z >= 10)
            {
                c++;
                z = 1;
            }
            else
            {
                z = 0;
            }
        }

        if (c == 0)
            printf("No carry operation.\n");
        else
            printf("%ld carry operation%s.\n", c, c > 1 ? "s" : "");

        scanf("%ld %ld", &a, &b);
    }

    return 0;
}