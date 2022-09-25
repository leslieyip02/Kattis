#include <stdio.h>

int main(void)
{
    unsigned long long n, k, d;
    scanf("%llu %llu", &n, &k);

    // k steps to get from 0 to k
    // 1 step to jump from k to highest multiple of k <= n
    // n mod k steps to get to n
    n--;
    d = k + 1 + n % k;
    printf("%llu\n", d < n ? d : n);

    return 0;
}
