#include <stdio.h>
#include <math.h>

int main(void)
{
    const double G = 9.81;
    const double PI = 3.14159265358979323846;
    double v, a, x, h1, h2, t, y;

    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf %lf %lf %lf", &v, &a, &x, &h1, &h2);
        a *= PI / 180;
        t = x / (v * cos(a));
        y = v * t * sin(a) - 0.5 * G * pow(t, 2);

        if (y > h1  && y - h1 >= 1 &&
            y < h2 && h2 - y >= 1)
            printf("Safe\n");
        else
            printf("Not Safe\n");
    }

    return 0;
}