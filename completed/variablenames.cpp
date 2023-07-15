#include <cstdio>
#include <unordered_map>
using namespace std;

#define ull unsigned long long

int main()
{
    int N, x, i;
    scanf("%i", &N);

    ull y;
    unordered_map<ull, int> c;
    while (N--)
    {
        scanf("%i", &x);

        auto itr = c.find(x);
        i = 1 + (itr == c.end() ? 0 : itr->second);
        while (c.find(i * x) != c.end())
        {
            i++;
        }

        y = i * x;
        c[x] = i;
        c[y] = 1;
        printf("%llu\n", y);
    }

    return 0;
}
