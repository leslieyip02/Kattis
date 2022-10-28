#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        
        int c = 0;
        string name, cat;
        map<string, int> attrs;

        while (n--)
        {
            cin >> name >> cat;
            
            if (attrs.find(cat) == attrs.end())
            {
                attrs[cat] = 0;
                c++;
            }

            attrs[cat]++;
        }

        int d = 1;
        for (auto attr : attrs)
            d *= attr.second + 1;

        cout << d - 1 << '\n';
    }

    return 0;
}