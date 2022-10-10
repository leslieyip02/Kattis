#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    int t = 1 << e;
    string s = to_string(t);

    int c = 0;
    for (int i = t; i <= n; i++)
    {
        if (to_string(i).find(s) != string::npos)
            c++;
    }

    cout << c << '\n';

    return 0;
}