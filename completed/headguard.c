#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[500];
    while (scanf("%s", s) != EOF)
    {
        int f = 0;
        char c = s[0];
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] != c)
            {
                printf("%i%c", f, c);

                c = s[i];
                f = 0;
            }
            
            f++;
        }
        printf("%i%c\n", f, c);
    }

    return 0;
}