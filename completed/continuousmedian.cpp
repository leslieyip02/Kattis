#include <cstdio>
#include <set>
using namespace std;

typedef unsigned long long ull;

int main()
{
    int T, N, x, y;
    scanf("%i", &T);
    while (T--)
    {
        scanf("%i", &N);
        ull s = 0;
        multiset<int> l;
        multiset<int> r;
        for (int i = 1; i <= N; i++)
        {
            scanf("%i", &x);
            if (l.empty())
            {
                l.insert(x);
            }
            else if (r.empty())
            {
                if (x < *l.begin())
                {
                    r.insert(*l.begin());
                    l.erase(l.begin());
                    l.insert(x);
                }
                else
                {
                    r.insert(x);
                }
            }
            else
            {
                if (x <= *l.rbegin())
                {
                    l.insert(x);
                }
                else
                {
                    r.insert(x);
                }
            }

            while (r.size() > l.size())
            {
                l.insert(*r.begin());
                r.erase(r.begin());
            }
            while (l.size() - r.size() > 1)
            {
                r.insert(*l.rbegin());
                l.erase(--l.end());
            }
            s += i & 1 ? *l.rbegin() : (*l.rbegin() + *r.begin()) / 2;
        }
        printf("%llu\n", s);
    }
    return 0;
}
