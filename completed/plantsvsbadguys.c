#include <stdio.h>

int main(void)
{
    int N, R;
    scanf("%i", &N);

    int m = 1e9;
    while (N--)
    {
        scanf("%i", &R);
        if (R < m)
        {
            m = R;
        }
    }

    printf("%i\n", m + 1);

    return 0;
}