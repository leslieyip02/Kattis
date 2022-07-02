#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, x, y;
    scanf("%i", &n);

    while (n != 0)
    {
        int start_x, start_y;
        scanf("%i %i", &start_x, &start_y);

        int x1 = start_x;
        int y1 = start_y;
        int x2, y2;

        double a = 0;
        for (int i = 1; i < n; i++)
        {
            scanf("%i %i", &x, &y);
            if (i % 2 == 0)
            {
                x1 = x;
                y1 = y;
                a += (x2 * y1) - (y2 * x1);
            }
            else
            {
                x2 = x;
                y2 = y;
                a += (x1 * y2) - (y1 * x2);
            }
        }
        
        if (n % 2 == 1)
            a += (x1 * start_y) - (y1 * start_x);
        else
            a += (x2 * start_y) - (y2 * start_x);

        a /= 2;

        printf("%s %.1f\n", a < 0 ? "CW" : "CCW",  fabs(a));

        scanf("%i", &n);
    }
    
    return 0;
}