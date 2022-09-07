#include <stdio.h>

int main(void)
{
    int n;
    scanf("%i", &n);

    int d[6] = { 0 };
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &a[i]);
        d[a[i] - 1]++;
    }

    int h = 6;
    while (h > 0 && d[h - 1] > 1 || d[h - 1] == 0)
        h--;
    
    if (h == 0)
    {
        printf("%s\n", "none");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i - 1] == h)
            {
                printf("%i\n", i);
                break;
            }
        }
    }

    return 0;
}