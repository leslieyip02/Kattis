#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string w, s;
    while (n--)
    {
        cin >> w;

        s = w.front();
        for (int i = 1; i < w.length(); i++)
        {
            if (w[i] != s.back())
            {
                s += w[i];
            }
        }

        if (s.length() > 1)
        {
            cout << s.front();
        }

        for (int i = 1; i < s.length() - 1; i++)
        {
            if (!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                  s[i] == 'o' || s[i] == 'u'))
            {
                cout << s[i];
            }
        }

        cout << s.back() << ' ';
    }

    return 0;
}