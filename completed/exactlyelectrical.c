#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b, c, d, t;
    scanf("%i %i %i %i %i", &a, &b, &c, &d, &t);
    
    int s = abs(a - c) + abs(b - d);
    int u = t - s;
    printf("%c\n", u >= 0 && u % 2 == 0 ? 'Y' : 'N');
    
    return 0;
}