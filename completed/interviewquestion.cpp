#include <iostream>
#include <vector>
using namespace std;

int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}

int main()
{
    int c, d;
    cin >> c >> d;

    string s;
    vector<int> p;
    vector<int> q;
    for (int i = c; i <= d; i++)
    {
        cin >> s;
        if (s.find("Fizz") != string::npos)
        {
            p.push_back(i);
        }
        if (s.find("Buzz") != string::npos)
        {
            q.push_back(i);
        }
    }

    int a, b;
    if (p.empty())
    {
        a = d + 1;
    }
    else
    {
        a = p.front();
        for (auto i : p)
        {
            a = gcd(i, a);
        }
    }
    if (q.empty())
    {
        b = d + 1;
    }
    else
    {
        b = q.front();
        for (auto i : q)
        {
            b = gcd(i, b);
        }
    }
    cout << a << ' ' << b << '\n';
    return 0;
}
