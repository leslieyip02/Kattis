#include <stdio.h>

int main(void)
{
    char c, d;

    d = '*';
    while ((c = getchar()) != EOF)
    {
        if (c == d)
        {
            continue;
        }
        else
        {
            printf("%c", c);
            d = c;
        }
    }

    return 0;
}