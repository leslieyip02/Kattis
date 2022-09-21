#include <stdio.h>

int main(void)
{
    int y;
    scanf("%i", &y);

    int m = 4 + (y - 2018) * 12;

    for (int i = -3; i <= 8; i++)
    {
        if ((m + i) % 26 == 4)
        {
            printf("yes\n");
            return 0;
        }
    }

    printf("no\n");
    return 0;
}