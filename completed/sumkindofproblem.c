#include <stdio.h>

int main(void)
{
    int p, k, n, s1, s2, s3;
    scanf("%i", &p);
    while (p--)
    {
        scanf("%i %i\n", &k, &n);
        s1 = 0, s2 = 0, s3 = 0;
        
        for (int i = 1; i <= n; i++)
            s1 += i;
        for (int i = 1; i <= n * 2; i+=2)
            s2 += i;
        for (int i = 2; i <= n * 2; i+=2)
            s3 += i;
            
        printf("%i %i %i %i\n", k, s1, s2, s3);
    }

    return 0;
}