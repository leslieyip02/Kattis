#include <iostream>
#include <string>
using namespace std;

string o(int n)
{
    if (n == 0)
    {
        return "{}";
    }

    string s = "{";
    for (int i = 0; i < n - 1; i++)
    {
        s += o(i) + ",";
    }

    s += o(n - 1) + "}";
    return s;
}

int main()
{
    int n;
    cin >> n;
    cout << o(n) << '\n';

    return 0;
}