#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int P, K, N;
    scanf("%i", &P);

    while (P--)
    {
        scanf("%i %i", &K, &N);
        vector<int> x(N);
        vector<int> y(N);
        for (int i = 0; i < N; i++)
        {
            scanf("%i", &x[i]);
            y[i] = x[i];
        }
        sort(x.begin(), x.end());

        int c = 0;
        int i = 0;
        int j = 0;
        while (i < N && j < N)
        {
            if (x[i] != y[j])
            {
                c++;
            }
            else
            {
                i++;
            }
            j++;
        }
        printf("%i %i\n", K, c);
    }

    return 0;
}
