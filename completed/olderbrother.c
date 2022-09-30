#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
    if (n == 1 || n == 2)
        return n - 1;

    if (n % 2 == 0)
        return 0;
        
    for (int i = 3; i <= (int) sqrt((double) n); i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

int main(void)
{
    int q;
    scanf("%i", &q);
    
    if (isPrime(q))
    {
        printf("yes\n");
        return 0;
    }
    
    for (int k = 2; k <= (int) sqrt((double) q); k++)
    {
        if (isPrime(k))
        {
            int j = k;
            while (j < q)
                j *= k;
                
            if (j == q)
            {
                printf("yes\n");
                return 0;
            }
        }
    }
    
    printf("no\n");
    
    return 0;
}
