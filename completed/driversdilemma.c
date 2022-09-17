#include <stdio.h>

int main(void)
{
    double c, x, m;
    scanf("%lf %lf %lf", &c, &x, &m);
    c /= 2;

    double f[6];
    for (int i = 0; i < 6; i++)
        scanf("%*i %lf", &f[i]);

    for (int i = 5; i >= 0; i--)
    {
        // speed
        int v = 55 + i * 5;

        // duration of trip
        double t = (double) m / v;

        // gallons needed for the trip
        double g = m / f[i] + x * t;

        if (g - c <= 0.000001)
        {
            printf("YES %i\n", v);
            return 0;
        }
    }

    printf("NO\n");

    return 0;
}
