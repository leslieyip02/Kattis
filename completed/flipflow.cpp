#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, s, n;
    cin >> t >> s >> n;


    int a, b, c, tmp;
    cin >> a;

    int upper = s;
    int lower = 0;
    while (--n)
    {
        cin >> b;
        c = b - a;

        tmp = max(upper - c, 0);
        upper = min(lower + c, s);
        lower = tmp;

        a = b;
    }

    upper -= (t - a);
    cout << max(upper, 0) << '\n';

    return 0;
}