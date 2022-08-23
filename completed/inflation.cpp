#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int c[n];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(c, c + n);

    double f = 1;
    for (int i = 1; i <= n; i++)
    {
        double r = (double) c[i - 1] / i;
        if (r > 1)
        {
            cout << "impossible\n";
            return 0;
        }

        if (r < f)
            f = r;
    }

    cout << f << endl;

    return 0;
}