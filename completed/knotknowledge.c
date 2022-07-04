#include <stdio.h>

int main(void)
{
    int n;
    scanf("%i", &n);

    int knots[n];
    for (int i = 0; i < n; i++)
        scanf("%i", &knots[i]);

    int known[n - 1];
    for (int i = 0; i < n - 1; i++)
        scanf("%i", &known[i]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (knots[i] == known[j])
                goto next;
        }
        printf("%i", knots[i]);
        return 0;

        next:
            continue;
    }

    printf("%i", knots[n - 1]);
    return 0;
}