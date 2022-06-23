#include <stdio.h>

int main(void)
{
    int a;
    int b = 1;
    for (int i = 0; i < 3; i++)
    {
        scanf("%i", &a);
        b *= a;
    }
    printf("%i", b);
    return 0;
}