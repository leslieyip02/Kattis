#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, w, h;
    scanf("%i", &n);
    scanf("%i", &w);
    scanf("%i", &h);
    double max = sqrt(pow(w, 2) + pow(h, 2));

    int x;
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &x);
        printf("%s", x <= max ? "DA\n" : "NE\n");
    }

    return 0;
}