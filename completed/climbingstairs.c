#include <stdio.h>

int main(void)
{
    int n, r, k;
    scanf("%i %i %i", &n, &r, &k);

    // go to office
    int s = k;

    // steps between office and registration
    int otr = r > k ? r - k : k - r;

    // if enough steps clocked, or
    // if enough steps can be clocked on the way to registration,
    int d = n - s - otr;
    if (d <= 0)
    {
        s += otr;
    }
    // if not enough, clock until enough
    // if parity of steps to clock and steps to registration don't match, + 1
    else
    {
        s = n + (n % 2 != r % 2 ? 1 : 0);
    }

    // go home
    printf("%i\n", s + r);

    return 0;
}