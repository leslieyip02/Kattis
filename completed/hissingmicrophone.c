#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(30 * sizeof(char));
    gets(s);

    do
    {
        if (*s == 's' && *(s + 1) == 's')
        {
            printf("hiss");
            return 0;
        }
        s++;
    } 
    while (*s != '\0');

    printf("no hiss");
    return 0;
}