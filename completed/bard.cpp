#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int N, E, K;
	map<int, int> v;
	v[1] = 0;

	scanf("%i %i", &N, &E);
	while (E--)
	{
		scanf("%i", &K);
		vector<int> p(K);
		bool b = false;
		for (int i = 0; i < K; i++)
		{
			scanf("%i", &p[i]);
			if (p[i] == 1)
			{
				b = true;
			}
		}

		if (b)
		{
			for (auto i : p)
			{
				v[i]++;
			}
		}
		else
		{
			for (auto i : p)
			{
				v[i] = v[1];
			}
		}
	}

	for (auto x : v)
	{
		if (x.second == v[1])
		{
			printf("%i\n", x.first);
		}
	}

	return 0;
}
