#include <iostream>
using namespace std;

int main()
{
    int s, v1, v2;
    cin >> s >> v1 >> v2;

    int n1 = s / v1;
    while ((s - n1 * v1) % v2 != 0 && n1 >= 0)
        n1--;

    if (n1 < 0)
    {
        cout << "Impossible\n";
    }
    else
    {
        int n2 = (s - n1 * v1) / v2;
        cout << n1 << ' ' << n2 << '\n';
    }

    return 0;
}