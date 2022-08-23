#include <iostream>
#include <string>
using namespace std;

string rt;

int replaced(string m)
{
    int c = 0;
    for (int i = 0; i < rt.length() - m.length() + 1; i++)
    {
        if (rt.substr(i, m.length()) == m)
        {
            c++;
            i += m.length() - 1;
        }
    }
    return c;
}

int main()
{
    cin >> rt;

    int l = rt.length();
    for (int i = 0; i < rt.length() - 1; i++)
    {
        for (int j = 2; j <= rt.length() - i; j++)
        {
            string m = rt.substr(i, j);
            int r = rt.length() - replaced(m) * (m.length() - 1) + m.length();
            if (r < l)
                l = r;
        }
    }

    cout << l << endl;

    return 0;
}