#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool b[1001];

int main(void)
{
    memset(b, false, 1001 * sizeof(bool));

    int n, x, y, z;
    scanf("%i", &n);

    while (n--)
    {
        scanf("%i", &x);
        b[x] = true;
    }
    
    y = -1; z = -1;
    for (int i = 1; i <= 1001; i++)
    {
        if (b[i])
        {
            if (y == -1)
                y = i;
            else
                z = i;
        }
        else if (y != -1)
        {
            if (z == -1)
                printf("%i ", y);
            else
                printf("%i%c%i ", y, z - y > 1 ? '-' : ' ', z);

            y = -1; z = -1;
        }
    }

    return 0;
}