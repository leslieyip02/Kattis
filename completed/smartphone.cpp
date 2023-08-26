#include <iostream>
using namespace std;

int keys(string target, string current)
{
	int m = min(current.size(), target.size());
	int i = 0;
	while (i < m && current[i] == target[i])
	{
		i++;
	}
	return abs((int) (current.size() - target.size())) + (m - i) * 2;
}

int main()
{
	int T;
	string x, y;

	cin >> T;
	while (T--)
	{
		cin >> x >> y;
		int m = keys(x, y);
		for (int i = 0; i < 3; i++)
		{
			cin >> y;
			m = min(1 + keys(x, y), m);
		}
		cout << m << '\n';
	}

	return 0;
}
