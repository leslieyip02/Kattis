#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define ull unsigned long long

int main()
{
    int N;
    scanf("%i", &N);

    vector<ull> s(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%llu", &s[i]);
    }
    sort(s.begin(), s.end());

    bool ok = false;
    for (int i = N - 1; i >= 2; i--)
    {
        if (s[i - 2] + s[i - 1] > s[i])
        {
            ok = true;
            break;
        }
    }

    printf("%spossible\n", ok ? "" : "im");
    return 0;
}