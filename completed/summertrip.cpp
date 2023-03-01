#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int t = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        // store what characters have appeared
        // bitshift practice
        int a = 0;
        for (int j = i + 1; j < n; j++)
        {
            int b = 1 << (int) s[j] - 97;
            if (s[j] == s[i])
            {
                break;
            }

            // not unique if bit already on
            if (!(a & b))
            {
                t++;
            }

            a |= b;
        }
    }

    cout << t << '\n';

    return 0;
}