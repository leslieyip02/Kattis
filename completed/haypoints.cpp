#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<string, int> d;
    
    int m, n;
    cin >> m >> n;
    
    string w;
    int p;
    while (m--)
    {
        cin >> w >> p;
        d.insert({ w, p });
    }

    while (n--)
    {
        int p = 0;
        cin >> w;
        do
        {
            if (d.find(w) != d.end())
                p += d[w];
            cin >> w;
        } 
        while (w != "."); 

        cout << p << '\n';      
    }

    return 0;
}
