#include <stdio.h>
#include <math.h>

int main(void)
{
    const double PI =  	3.14159265358979323846;

    int h, v;
    scanf("%i", &h);
    scanf("%i", &v);

    printf("%i\n", (int) ceil(h / sin(PI * v / 180)));

    return 0;
}