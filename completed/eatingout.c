#include <stdio.h>

int main(void)
{
    int m, a, b, c;
    scanf("%i %i %i %i", &m, &a, &b, &c);

    // check whether there is any overlap for all 3 
    printf("%spossible\n", 2 * m - a - b < c ? "im" : "");

    return 0;
}