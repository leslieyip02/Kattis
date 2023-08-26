#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int P;
	cin >> P;

	vector<int> p;
	for (int i = 2; i <= P; i++)
	{
		bool ok = true;
		for (int j : p)
		{
			if (i % j == 0)
			{
				ok = false;
				break;
			}
		}

		if (ok)
		{
			p.push_back(i);
		}
	}

	vector<unsigned long long> w(p.size(), 0);
	w[0] = 1;
	for (int i = 1; i < p.size(); i++)
	{
		for (int j = i - 1; j >= 0 && p[i] - p[j] <= 14; j--)
		{
			w[i] += w[j];
		}
	}
	cout << w.back() << '\n';

	return 0;
}
