#include <iostream>
#include <map>
using namespace std;

int main()
{
    int r, n;
    string s;
    cin >> r >> s >> n;
    
    string f[n];
    for (int i = 0; i < n; i++)
        cin >> f[i];

    map<char, char> b = {{ 'R', 'S' }, { 'P', 'R' }, { 'S', 'P' }};

    int x = 0;
    int y = 0;
    for (int i = 0; i < r; i++)
    {
        map<char, int> c = {{ 'R', 0 }, { 'P', 0 }, { 'S', 0 }};
        
        for (int j = 0; j < n; j++)
        {
            c[f[j][i]]++;

            if (f[j][i] == b[s[i]])
                x += 2;
            else if (f[j][i] == s[i])
                x++;
        }

        int z = 0;
        for (auto k : c)
            z = max(c[b[k.first]] * 2 + k.second, z);

        y += z;
    }
    
    cout << x << '\n';
    cout << y << '\n';
    
    return 0;
}