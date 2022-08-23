#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int r, n, rm;
    scanf("%i %i", &r, &n);

    if (n >= r)
    {
        printf("too late\n");
        return 0;
    }

    bool rms[100] = { false };
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &rm);
        rms[rm - 1] = true;
    }

    for (int i = 0; i < r; i++)
    {
        if (!rms[i])
        {
            printf("%i\n", i + 1);
            break;
        }
    }

    return 0;
}