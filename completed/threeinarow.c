#include <stdio.h>

int main()
{
    int x = 1;
    int y = 2;
    int z = 3;
    int N;
    scanf("%i", &N);
    int p = x * y * z;
    int c = 0;
    while (p < N) {
        c++;
        x = y;
        y = z;
        z++;
        p = x * y * z;
    }
    printf("%i\n", c);
    return 0;
}