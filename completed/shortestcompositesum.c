#include <stdio.h>

int main(void)
{
    unsigned long long n, m;
    scanf("%llu", &n);

    if (n <= 12)
        m = 4;
    else
        m = ((n + 1) / 2 - 5) * 2;

    printf("2\n%llu %llu\n", m, n - m);

    return 0;
}

/*

8  = 4 + 4
10 = 4 + 6
12 = 4 + 8

13 = 4 + 9
14 = 4 + 10
15 = 6 + 9
16 = 6 + 10
17 = 8 + 9
18 = 8 + 10
...
n = (ceil(n / 2) - 5) * 2 + isOdd(n) ? 9 : 10

*/