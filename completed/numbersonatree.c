#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int h;
    scanf("%i", &h);

    int r = 2;
    for (int i = 0; i < h; i++)
        r <<= 1;
    r--;

    char* p = (char*) malloc(h * sizeof(char));
    if (scanf("%s", p) != EOF)
    {
        int d = *p++ == 'L' ? 1 : 2;
        r -= d;

        while (*p != '\0')
        {
            d <<= 1;

            if (r % 2 == 0 && *p == 'R')
                d++;
            if (r % 2 == 1 && *p == 'L')
                d--;

            r -= d; 
            p++;
        }
    }

    printf("%i\n", r);

    return 0;
}