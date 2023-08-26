#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n, t, i;
    scanf("%i", &n);

    vector<int> p(n);
    for (int j = 0; j < n; j++) 
    {
        scanf("%i %i", &t, &i);
        p[--i] = t;
    }

    int c = 1;
    int l = 0;
    for (int j = 0; j < n; j++)
    {
        if (p[j] > c)
        {
            l += p[j] - c;
        }
        c = max(p[j], c) + 1;
    }
    printf("%i\n", l);

    return 0;
}
