#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    char *s = malloc(2048 * sizeof(char));
    gets(s);

    int n = 0;
    while (*s != '\0')
    {
        if (*s == ':' ||
            *s == ';')
        {
            if ((*(s + 1) == '-' && *(s + 2) == ')') ||
                *(s + 1) == ')')
                printf("%i\n", n);
        }

        s++;
        n++;
    }

    return 0;
}