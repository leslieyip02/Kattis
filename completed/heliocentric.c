#include <stdio.h>

int main(void)
{
    int c = 0;
    int e, m, d;
    while (scanf("%i %i", &e, &m) != EOF)
    {
        d = 0;
        while (!(e == 0 && m == 0))
        {
            e = (e + 1) % 365;
            m = (m + 1) % 687;
            d++;
        }
        
        printf("Case %i: %i\n", ++c, d);
    }

    return 0;
}