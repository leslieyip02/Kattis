#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;

    getline(cin, s);
    n = stoi(s);
    while (n--)
    {
        getline(cin, s);
        for (int i = 1; i <= s.length(); i++)
        {
            bool found = true;
            string ss = s.substr(0, i);

            for (int j = i; j < s.length(); j += i)
            {
                string sss = s.substr(j, i);
                if (sss.length() < i)
                {
                    found = sss == ss.substr(0, sss.length());
                }
                else
                {
                    if (sss != ss)
                    {
                        found = false;
                        break;
                    }
                }
            }

            if (found)
            {
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}