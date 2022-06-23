#include <stdio.h>

int main(void)
{
    int n, k, o;
    scanf("%i", &n);
    for (int i = 0; i < n; i++)
    {
        int a = 0;
        scanf("%i", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%i", &o);
            a += o;
        }
        printf("%i\n", a - (k - 1));
    }
    return 0;
}