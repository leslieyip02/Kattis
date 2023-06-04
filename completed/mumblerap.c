#include <stdio.h>
#include <ctype.h>

int main()
{
    int N;
    scanf("%i", &N);

    char s[N];
    scanf("%s", &s);

    int A = 0;
    for (int i = 0; i < N; i++)
    {
        int a = 0;
        for (int j = 0; j < N; j++)
        {
            if (isdigit(s[i + j]))
            {
                a *= 10;
                a += (int) (s[i + j] - '0');
            }
            else
            {
                i += j;
                break;
            }
        }

        if (a > A)
        {
            A = a;
        }
    }

    printf("%i\n", A);

    return 0;
}