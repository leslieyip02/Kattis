#include <stdio.h>

int main(void)
{
    unsigned long long n;
    scanf("%llu", &n);

    // longest sequence is 2 + 2 + ... + 2 + 2 (or 3 if n is odd)
    printf("%llu", n / 2);

    return 0;
}