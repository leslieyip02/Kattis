#include <cstdio>
#include <vector>
#include <bitset>
#include <unordered_set>
using namespace std;

#define MAX_T 100

int main()
{
    int P, T, i, j;
    scanf("%i %i", &P, &T);

    vector<bitset<MAX_T>> p(P);
    while (scanf("%i %i", &i, &j) != EOF)
    {
        p[--i][--j] = 1;
    }

    int o = 0;
    unordered_set<int> x;
    for (i = 0; i < P; i++)
    {
        if (x.find(i) == x.end())
        {
            o++;
            for (j = i; j < P; j++)
            {
                if ((p[i] ^ p[j]) == 0)
                {
                    x.insert(j);
                }
            }
        }
    }
    printf("%i\n", o);

    return 0;
}