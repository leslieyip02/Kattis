#include <stdio.h>

int main(void)
{
    int n, m;
    char t;

    n = m = 0;
    while ((t = getchar()) != EOF)
    {
        if (t == '0')
        {
            n++;
        }
        else
        {
            m = n > m ? n : m;
            n = 0;
        }
    }

    printf("%i\n", (m + 1) / 2);

    return 0;
}