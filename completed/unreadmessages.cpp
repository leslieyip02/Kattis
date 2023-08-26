#include <cstdio>
#include <map>
using namespace std;

int main()
{
    int n, m, x, y;
    scanf("%i %i", &n, &m);

    unsigned long long u = 0;
    map<int, int> s;
    for (int i = 1; i <= m; i++)
    {
        scanf("%i", &x);

        auto itr = s.find(x);
        y = itr == s.end() ? 0 : itr->second;

        u += n;
        u -= i - y;
        s[x] = i;
        printf("%llu\n", u);
    }

    return 0;
}