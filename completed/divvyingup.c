#include <stdio.h>

int main(void)
{
    int n, w;
    scanf("%i", &n);

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &w);
        total = (total + w % 3) % 3;
    }

    printf("%s\n", total % 3 == 0 ? "yes" : "no");

    return 0;
}