#include <stdio.h>

int main(void)
{
    int k, y, c1, c2, e, f;
    scanf("%i", &k);
    
    e = 100000;
    while (k--)
    {
        scanf("%i %i %i", &y, &c1, &c2);
        f = c1 < c2 ? c1 : c2;
        while (f % c1 != 0 || f % c2 != 0)
            f++;
        f += y;
        e = f < e ? f : e;
    }
    
    printf("%i\n", e);
    
    return 0;
}

