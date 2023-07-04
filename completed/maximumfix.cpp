#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, b;
    scanf("%i", &n);

    map<int, int> d;
    for (int i = 1; i <= n; i++)
    {
	scanf("%i", &a);
	b = a > i ? n - a + i : i - a;

	if (d.find(b) == d.end())
	{
	    d.insert({b, 0});
	}
	d[b]++;
    }

    auto m = max_element(d.begin(), d.end(),
	[] (const pair<int, int> &p1, const pair<int, int> &p2)
	{
	    return p1.second < p2.second;
	});
    int k = m->first;
    int f = m->second;

    printf("%i %i\n", k, f);
    return 0;
}
