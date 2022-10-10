#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b, c;
    scanf("%i %i %i", &a, &b, &c);
    
    int ab = b - a;
    int bc = c - b;
    
    if (ab == bc)
        printf("cruised\n");
    else if ((ab > 0) != (bc > 0))
        printf("turned\n");
    else if (abs(ab) < abs(bc))
        printf("accelerated\n");
    else
        printf("braked\n");

    return 0;
}