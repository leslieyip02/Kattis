#include <stdio.h>

int main(void)
{
    int n1, n2;
    scanf("%i %i", &n1, &n2);

    int cw = (n2 - n1 + 360) % 360;
    int ccw = -((n1 - n2 + 360) % 360);
    printf("%i\n", cw <= -ccw ? cw : ccw);

    return 0;
}