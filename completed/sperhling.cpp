#include <iostream>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int n = 0;
    if (s1.length() > s2.length())
    {
        n += s1.length() - s2.length();
        s1 = s1.substr(0, s2.length());
    }

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
        {
            n += (s1.length() - i) * 2;
            break;
        }
    }

    n += s2.length() - s1.length();
    cout << n << '\n';

    return 0;
}