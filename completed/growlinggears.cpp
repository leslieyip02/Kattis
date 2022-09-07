#include <iostream>
#include <cmath>
using namespace std;

double mid(int a, int b, int c)
{
    int x1 = (-b + sqrt(pow(b, 2) + 4 * a * c)) / (-2 * a);
    int x2 = (-b - sqrt(pow(b, 2) + 4 * a * c)) / (-2 * a);

    return (x1 + x2) / 2.0;
}

int main()
{
    int t, n, a, b, c, g;
    cin >> t;
    while (t--)
    {
        cin >> n;
        double m[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b >> c;
            double x = mid(a, b, c);
            m[i] = -a * pow(x, 2) + b * x + c;
        }

        double h = 0;
        for (int i = 0; i < n; i++)
        {
            if (m[i] > h)
            {
                h = m[i];
                g = i;
            }
        }
        
        cout << g + 1 << '\n';
    }

    return 0;
}