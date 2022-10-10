#include <stdio.h>

int main(void)
{
    int n;
    scanf("%i", &n);

    char s[n];
    scanf("%s", &s);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            if (i < n - 1 && s[i + 1] != '1')
                s[i + 1] = '2';
            
            if (i < n - 2 && s[i + 2] != '1')
                s[i + 2] = '3';
        }
    }

    int c = 0;
    for (int i = 0; i < n; i++)
        if (s[i] != '0')
            c++;

    printf("%i\n", c);

    return 0;
}