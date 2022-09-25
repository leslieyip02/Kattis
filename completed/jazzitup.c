#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void)
{
    int n, m, nm, i, k, u;
    scanf("%i", &n);

    for (m = 2; m < n; m++)
    {
        nm = n * m;
        u = (int) sqrt(nm);
        u *= u;

        bool spicyJazz = true;
        for (i = 2, k = i * i; k <= u; i++, k = i * i)
        {
            if (nm % k == 0)
            {
                spicyJazz = false;
                break;
            }
        }

        if (spicyJazz)
            break;
    }

    printf("%i\n", m);

    return 0;
}
