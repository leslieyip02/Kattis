#include <iostream>
using namespace std;

int main()
{
    int a, b, c, l;
    cin >> a >> b;

    c = 0;
    l = a > b ? b : a;
    for (int i = 1; i <= l; i++)
        if (a % i == 0 && b % i == 0)
            c = i;
    cout << c << endl;

    return 0;
}