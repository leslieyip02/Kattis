#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n;
    string d;

    getline(cin, d);
    n = stoi(d);

    int e = 1;
    while (e < n)
    {
        int l = (int) log10(e) + 1;

        d = "";
        while (l--)
            d += getchar();

        if (stoi(d) != e)
        {
            cout << e << '\n';
            return 0;
        }

        e++;
    }

    cout << n << '\n';

    return 0;
}