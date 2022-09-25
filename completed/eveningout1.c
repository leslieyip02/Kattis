#include <stdio.h>

int main(void)
{
    long long a, b, c, d;
    scanf("%lli %lli", &a, &b);

    c = a % b;
    d = b - c;
    printf("%lli\n", c < d ? c : d);

    return 0;
}
