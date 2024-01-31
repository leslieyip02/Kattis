#include <stdio.h>

#define MAX 6

int main()
{
    char message[MAX * MAX] = {0};
    int N, M;
    scanf("%i %i", &N, &M);

    int i = 0;
    while (N--)
    {
        char row[MAX + 1];
        scanf("%s", row);
        for (int j = 0; j < M; j++)
        {
            int a = *(row + j) - 97;
            if (a >= 0 && a < 26)
            {
                *(message + i++) = *(row + j);
            }
        }
    }
    printf("%s\n", message);
    return 0;
}