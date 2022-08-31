#include <iostream>
#include <string>
using namespace std;

string encode(string s)
{
    string o = "";

    char c = s[0];
    int l = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == c)
        {
            l++;
        }
        else
        {
            o += c + to_string(l);

            c = s[i];
            l = 1;
        }
    }

    o += c + to_string(l);

    return o + '\n';
}

string decode(string s)
{
    string o = "";
    for (int i = 0; i < s.length(); i += 2)
        for (int j = 0; j < (int) s[i + 1] - '0'; j++)
            o += s[i];
    return o + '\n';
}

int main()
{
    string m, s;
    cin >> m >> s;

    cout << (m == "E" ? encode(s) : decode(s));

    return 0;
}