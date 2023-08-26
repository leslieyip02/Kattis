#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

int main()
{
    int F, L, N;
    map<int, int> f;
    int m = 1;
    scanf("%i", &F);
    while (F--)
    {
        scanf("%i", &L);
        while (L--)
        {
            scanf("%i", &N);
            if (N)
            {
                f[N]++;
                m = max(N, m);
            }
        }
    }

    int t = 1;
    int s = 0;
    for (int i = 2; i <= m; i++)
    {
        int x = 0;
        for (auto p : f)
        {
            if (i <= p.first)
            {
                x += p.first / i * (i - 1) * p.second;
            }
        }
        if (x > s)
        {
            t = i;
            s = x;
        }
    }
    printf("%i\n%i\n", t, s);
    return 0;
}
