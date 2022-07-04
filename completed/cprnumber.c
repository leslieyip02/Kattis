#include <stdio.h>

int v[10] = { 4, 3, 2, 7, 6, 5, 4, 3, 2, 1 };

int main(void)
{
    char num[11];
    scanf("%s", num);

    int sum = 0;
    int i = 0;
    for (char *s = num; *s != '\0'; s++)
    {
        if (*s == '-')
            continue;
        sum += (int) (*s - '0') * v[i];
        i++;        
    }

    printf("%i", sum % 11 == 0 ? 1 : 0);
    
    return 0;
}