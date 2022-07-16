#include <iostream>
using namespace std;

int main()
{
    int n, t1, t2, d1, d2;
    cin >> n;

    int dx = 0;
    cin >> t1 >> d1;
    for (int i = 1; i < n; i++)
    {
        cin >> t2 >> d2;
        dx = max((d2 - d1) / (t2 - t1), dx);
        t1 = t2;
        d1 = d2;
    }

    cout << dx << endl;

    return 0;
}