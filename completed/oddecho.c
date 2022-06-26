#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100 * sizeof(char));

    int n;
    scanf("%i", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s);
        if (i % 2 == 1)
            printf("%s\n", s);
    }

    return 0;
}