#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int n, a, b;
    
    int w1 = 0;
    int w2 = 1001;
    bool g = true;

    scanf("%i", &n);
    while (n--)
    {
        scanf("%i %i", &a, &b);
        w1 = w1 < a ? a : w1;
        w2 = w2 > b ? b : w2;

        if (w2 < w1)
        {
            g = false;
            break;
        }
    }

    printf("%s", g ? "gunilla has a point" : "edward is right");

    return 0;
}