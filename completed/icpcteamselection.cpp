#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t, n;
    scanf("%i", &t);
    while (t--)
    {
        scanf("%i", &n);

        vector<int> P(n * 3);
        for (int i = 0; i < n * 3; i++)
        {
            scanf("%i", &P[i]);
        }

        sort(P.begin(), P.end());

        int S = 0;
        int j = 3 * n - 2;
        while (n--)
        {
            S += P[j];
            j -= 2;
        }

        printf("%i\n", S);
    }

    return 0;
}