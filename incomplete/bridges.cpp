#include <iostream>
#include <vector>
using namespace std;

#define inf 1e9

int main()
{
	int n, m, a, b, c;
	cin >> n >> m;

	vector<vector<int>> p(n, vector<int>(n, inf));
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		p[a - 1][b - 1] = p[b - 1][a - 1] = c;
	}

	vector<int> d(n, inf);
	d[0] = 0;
	vector<int> q(n, 0);

	for (int i = 0; i < n - 1; i++)
	{
		int k;
		int t = inf;
		for (int j = 0; j < n; j++)
		{
			if (!q[j] && d[j] <= t)
			{
				k = j;
				t = d[j];
			}
		}
		q[k] = 1;

		for (int j = 0; j < n; j++)
		{
			if (!q[j] && p[k][j] != inf && d[k] != inf)
			{
				d[j] = min(d[k] + p[k][j], d[j]);
			}
		}
	}

	cout << d[n - 1] << '\n';
	return 0;
}
