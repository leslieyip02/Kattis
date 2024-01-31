#include <stdio.h>

#define MAX 8

int main()
{
    char N[MAX];
    char M[MAX];
    scanf("%s %s", N, M);

    int x = 0;
    for (int i = 0; *(N + i) != '\0'; i++)
    {
        int v = *(N + i) - '0';
        if (v == 5)
        {
            v = 2;
        }
        else if (v == 2)
        {
            v = 5;
        }
        for (int j = 0; j < i; j++)
        {
            v *= 10;
        }
        x += v;
    }
    int y = 0;
    for (int i = 0; *(M + i) != '\0'; i++)
    {
        int v = *(M + i) - '0';
        if (v == 5)
        {
            v = 2;
        }
        else if (v == 2)
        {
            v = 5;
        }
        for (int j = 0; j < i; j++)
        {
            v *= 10;
        }
        y += v;
    }
    printf("%i\n", (x < y) + 1);
    return 0;
}