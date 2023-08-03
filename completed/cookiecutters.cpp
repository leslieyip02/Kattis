#include <iostream>
#include <iomanip>
#include <cmath>
#include <utility>
#include <vector>
using namespace std;

int main()
{
	int N, A;
	cin >> N;
	vector<pair<double, double>> p(N);
	for (int i = 0; i < N; i++)
	{
		cin >> p[i].first >> p[i].second;
	}

	double r = p.back().first * p.front().second - p.back().second * p.front().first;
	for (int i = 0; i < N - 1; i++)
	{
		r += p[i].first * p[i + 1].second;
		r -= p[i].second * p[i + 1].first;
	}

	cin >> A;
	r = sqrt(A / (0.5 * abs(r)));
	double mx = p[0].first;
	double my = p[0].second;
	for (int i = 0; i < N; i++)
	{
		p[i].first *= r;
		p[i].second *= r;
		mx = min(p[i].first, mx);
		my = min(p[i].second, my);
	}

	cout << setprecision(16);
	for (auto x : p)
	{
		cout << x.first - mx << ' ' << x.second - my << '\n';
	}

	return 0;
}
