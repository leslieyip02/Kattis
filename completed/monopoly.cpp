#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    map<int, double> p;

    int total = 0;
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            int r = i + j;
            if (p.find(r) == p.end())
            {
                p.insert({r, 0.0});
            }

            p[r]++;
            total++;
        }
    }

    int a;
    double q = 0.0;
    while (n--)
    {
        cin >> a;
        q += p[a];
    }

    cout << setprecision(16) << q / total << '\n';
}