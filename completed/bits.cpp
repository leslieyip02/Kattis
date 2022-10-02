#include <iostream>
#include <string>
using namespace std;

int bits(int n)
{
    int b = 0;
    while (n > 0)
    {
        if (n & 1)
            b++;
        n >>= 1;
    }

    return b;
}

int main()
{
    int t, c;
    string x;

    cin >> t;
    while (t--)
    {
        cin >> x;
        c = 0;
        for (int i = 1; i <= x.length(); i++)
            c = max(bits(stoi(x.substr(0, i))), c);

        cout << c << '\n';
    }

    return 0;
}