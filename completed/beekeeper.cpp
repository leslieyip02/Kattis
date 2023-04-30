#include <iostream>
using namespace std;

bool is_vowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' ||
           c == 'o' || c == 'u';
}

int main()
{
    int n;
    cin >> n;
    while (n)
    {
        string s, t;
        int p = -1;

        while (n--)
        {
            cin >> s;

            int q = 0;
            for (int i = 0; i < s.length() - 1; i++)
            {
                if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                     s[i] == 'o' || s[i] == 'u' || s[i] == 'y') &&
                    s[i] == s[i + 1])
                {
                    q++;
                }
            }

            if (q > p)
            {
                p = q;
                t = s;
            }
        }

        cout << t << '\n';

        cin >> n;
    }

    return 0;
}