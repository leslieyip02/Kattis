#include <stdio.h>

int main(void)
{
    int w, p;
    scanf("%i %i", &w, &p);

    int l[p + 1];
    for (int i = 0; i < p; i++)
        scanf("%i", &l[i]);
    l[p] = w;

    for (int n = 1; n <= w; n++)
    {
        for (int i = p; i >= 0; i--)
        {
            if (l[i] == n)
            {
                printf("%i ", n);
                goto next;
            }

            for (int j = i - 1; j >= 0; j--)
            {
                if (l[i] - l[j] == n)
                {
                    printf("%i ", n);
                    goto next;
                }
            }
        }
        
        next:
            continue;
    }
    printf("\n");

    return 0;
}