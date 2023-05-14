#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int b;
    cin >> b;

    string d;
    map<string, int> v;
    for (int i = 0; i < b; i++)
    {
        cin >> d;
        v[d] = i;
    }

    string x, y;
    cin >> x;

    vector<int> z;
    int i = 0;
    int j = 1;
    while (i < x.length())
    {
        y = x.substr(i, j);
        if (v.find(y) != v.end())
        {
            z.push_back(v[y]);
            i += j;
            j = 1;
        }
        else
        {
            j++;
        }
    }

    int w = 0;
    for (int i = 0; i < z.size(); i++)
    {
        w += z[i] * pow(b, z.size() - i - 1);
    }

    cout << w << '\n';

    return 0;
}