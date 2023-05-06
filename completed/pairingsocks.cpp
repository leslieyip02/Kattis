#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(2 * n);
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        cin >> a[i];
    }

    vector<int> b;
    int c = 0;
    while (!a.empty())
    {
        if (!b.empty() && a.back() == b.back())
        {
            a.pop_back();
            b.pop_back();
        }
        else
        {
            b.push_back(a.back());
            a.pop_back();
        }

        c++;
    }

    if (b.empty())
    {
        cout << c << '\n';
    }
    else
    {
        cout << "impossible\n";
    }

    return 0;
}