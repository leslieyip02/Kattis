#include <stdio.h>

int main(void)
{
    int a, b, c, d, e, s;
    scanf("%i %i %i %i %i", &a, &b, &c, &d, &e);
    scanf("%i", &s);

    printf("%c", s >= a ? 'A' :
                s >= b ? 'B' :
                s >= c ? 'C' :
                s >= d ? 'D' :
                s >= e ? 'E' : 'F');

    return 0;
}