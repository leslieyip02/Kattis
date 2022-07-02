#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int l, d, x;
    scanf("%i\n%i\n%i", &l, &d, &x);

    int min = 10001;
    int max = 0;
    for (int i = l; i <= d; i++)
    {
        int n = 0;
        char *s = malloc(10 * sizeof(char));
        sprintf(s, "%i", i);
        while (*s != '\0')
        {
            n += *s - '0';
            s++;
        }
        
        if (n == x)
        {
            min = i < min ? i : min;
            max = i > max ? i : max;
        }
    }

    printf("%i\n%i", min, max);
    return 0;
}