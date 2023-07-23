#include <cstdio>
#include <cmath>
#include <unordered_map>
using namespace std;

int main()
{
    int N, i;
    scanf("%i", &N);
    unordered_map<int, int> s;
    while (N--)
    {
        scanf("%i", &i);
        if (s.find(i) == s.end())
        {
            s[i] = 0;
        }
        s[i]++;
    }

    int c = 0;
    for (auto x : s)
    {
        c += ceil(x.second / (x.first + 1.0)) * (x.first + 1.0);
    }
    printf("%i\n", c);

    return 0;
}
