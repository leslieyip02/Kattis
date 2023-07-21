#include <iostream>
using namespace std;

double solve(double x, double a, double b)
{
    return x * x + a * x + b;
}

int main()
{
    double A, B, C, D, x, y;
    cin >> A >> B >> C >> D;

    if (A == C)
    {
        x = A / -2.0;
        y = max(solve(x, A, B), solve(x, C, D));
    }
    else
    {
        double x1 = A / -2.0;
        double y1 = max(solve(x1, A, B), solve(x1, C, D));
        double x2 = C / -2.0;
        double y2 = max(solve(x2, A, B), solve(x2, C, D));
        double x3 = (D - B) / (A - C);
        double y3 = solve(x3, A, B);

        double m = min(y1, min(y2, y3));
        if (m == y1)
        {
            x = x1;
            y = y1;
        }
        else if (m == y2)
        {
            x = x2;
            y = y2;
        }
        else
        {
            x = x3;
            y = y3;
        }
    }

    cout << x << ' ' << y << '\n';
    return 0;
}