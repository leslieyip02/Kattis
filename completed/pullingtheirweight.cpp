#include <cstdio>
#include <map>
using namespace std;

int main()
{
    int m, w;
    scanf("%i", &m);

    int x = 0;
    map<int, int> a;
    for (int i = 0; i < m; i++)
    {
        scanf("%i", &w);
        a[w]++;
        x += w;
    }

    int y = 0;
    int z = 0;
    for (w = a.begin()->first; w < a.rbegin()->first; w++)
    {
        y += z;
        z = 0;
        auto itr = a.find(w);
        if (itr != a.end())
        {
            z = itr->first * itr->second;
            x -= z;
        }
        if (x == y)
        {
            break;
        }
    }
    printf("%i\n", w);
    return 0;
}
