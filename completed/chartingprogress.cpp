#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string r;
    while (getline(cin, r))
    {
        int l = r.length();
        vector<int> v;
        while (r.length() > 0)
        {
            int s = 0;
            for (char c : r)
                if (c == '*')
                    s++;
            v.push_back(s);
            getline(cin, r);
        }

        int o = 0;
        for (int d : v)
        {
            string s = "";
            for (int i = 0; i < o; i++)
                s += '.';
                
            for (int i = 0; i < d; i++)
                s = '*' + s;
                
            while (s.length() < l)
                s = '.' + s;
                
            o += d;

            cout << s << '\n';
        }
        
        cout << endl;
    }

    return 0;
}