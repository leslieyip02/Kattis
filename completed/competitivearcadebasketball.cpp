#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n, p, m;
	cin >> n >> p >> m;

	string s;
	map<string, int> c;
	while (n--)
	{
		cin >> s;
		c[s] = 0;
	}

	bool ok = false;
	while (m--)
	{
		cin >> s >> n;
		if (c[s] == -1)
		{
			continue;
		}

		c[s] += n;
		if (c[s] >= p)
		{
			ok = true;
			cout << s << " wins!\n";
			c[s] = -1;
		}
	}

	if (!ok)
	{
		cout << "No winner!\n";
	}

	return 0;
}
