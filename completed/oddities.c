#include <stdio.h>

int main(void)
{
    int n, x;
    scanf("%i", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%i", &x);
        printf("%i is %s\n", x, x % 2 == 0 ? "even" : "odd");
    }

    return 0;
}