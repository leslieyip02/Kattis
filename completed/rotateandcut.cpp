#include <iostream>
using namespace std;

int main()
{
    int t, n, l;
    string s;
    
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        for (int i = 0; i < n; i++)
        {
            if (s.length() <= 3)
                break;
                
            l = s.length() / 4;
            s =  i % 2 == 0 ? s.substr(l) : s.substr(0, s.length() - l);
        }
        
        cout << s << '\n';
    }
}