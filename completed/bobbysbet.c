#include <stdio.h>
#include <math.h>

int nCr(int n, int r)
{
    if (n == r || r == 0)
        return 1;

    int x = n;
    for (int i = r + 1; i < n; i++)
        x *= i;

    int y = n - r;
    for (int i = 2; i < n - r; i++)
        y *= i;

    return x / y;
}

// find probability of getting x out of n rolls
double pdf(int x, int n, double p)
{
    return nCr(n, x) * pow(p, x) * pow(1 - p, n - x);
}

int main(void)
{
    int n, r, s, x, y, w;
    scanf("%i", &n);

    while (n--)
    {
        scanf("%i %i %i %i %i", &r, &s, &x, &y, &w);

        // probability of getting a roll ≥ r
        double a = (double) (s - r + 1) / s;

        // expected winnings
        double e = 0;

        // losing
        for (int i = 0; i < x; i++)
            e -= pdf(i, y, a);

        // winning
        for (int i = x; i <= y; i++)
            e += pdf(i, y, a) * (w - 1);

        printf("%s\n", e > 0 ? "yes" : "no");
    }

    return 0;
}