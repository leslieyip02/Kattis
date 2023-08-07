#include <iostream>
#include <cmath>
#include <vector>
#include <random>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int[3]> c(n);
	for (int i = 0; i < n; i++)
	{
		cin >> c[i][0] >> c[i][1] >> c[i][2];
	}

	// sampling
	int x = 0;
	int y = 1e6;
	double smin = -20;
	double smax = 20;
	uniform_real_distribution r(smin, smax);
	default_random_engine re;
	for (int i = 0; i < y; i++)
	{
		double xi = r(re);
		double yi = r(re);
		for (auto p : c)
		{
			if (sqrt(pow(p[0] - xi, 2) + pow(p[1] - yi, 2)) <= p[2])
			{
				x++;
				break;
			}
		}
	}

	cout << (double) x / y * pow(smax - smin, 2) << '\n';
	return 0;
}
