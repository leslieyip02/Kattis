#include <stdio.h>

int main()
{
    int B, L;
    scanf("%i %i", &B, &L);
    int m = B > L ? L : B;
    printf("%i\n", m * 2);
    return 0;
}