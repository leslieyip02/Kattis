#include <cstdio>
using namespace std;

#define ull unsigned long long

int main()
{
    int n, l, r;
    scanf("%i", &n);

    while (n--)
    {
        scanf("%i %i", &l, &r);

        ull z = (l + r);
        ull s = 1 + r + (z * (z + 1)) / 2;

        printf("%llu\n", s);
    }

    return 0;
}