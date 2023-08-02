#include <iostream>
using namespace std;

int main()
{
	int n, m, a0, b0, a1, b1;
	while (cin >> n >> m)
	{
		if (!n && !m)
		{
			break;
		}

		a0 = b0 = 1;
		double r0 = 1e9;
		bool ok = false;
		while (n--)
		{
			cin >> a1 >> b1;
			if (a1 > m)
			{
				continue;
			}

			double r1 = (double) b1 / a1;
			if (r1 < r0 || (r1 == r0 && b1 > b0))
			{
				ok = true;
				a0 = a1;
				b0 = b1;
				r0 = r1;
			}
		}

		if (ok)
		{
			cout << "Buy " << a0 << " tickets for $" << b0 << '\n';
		}
		else
		{
			cout << "No suitable tickets offered\n";
		}
	}

	return 0;
}
