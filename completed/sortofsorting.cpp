#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n)
    {
        string names[n];
        for (int i = 0; i < n; i++)
            cin >> names[i];

        stable_sort(names, names + n, [](const string &a, const string &b)
        {
            return a.substr(0, 2) < b.substr(0, 2);
        });

        for (string name : names)
            cout << name << '\n';
        cout << '\n';

        cin >> n;
    }

    return 0;
}