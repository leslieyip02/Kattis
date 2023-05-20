#include <iostream>
#include <map>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int t = 'R' + 'B' + 'L';
    map<char, char> v = {{'R', 'S'}, {'B', 'K'}, {'L', 'H'}};
    for (int i = 0; i < s.length(); i++)
    {
        if (i + 2 < s.length())
        {
            if (s[i] + s[i + 1] + s[i + 2] == t)
            {
                cout << 'C';
                i += 2;
                continue;
            }
        }

        cout << v[s[i]];
    }

    return 0;
}