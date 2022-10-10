#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> atomise(string m, int k = 1)
{
    vector<int> t(26, 0);
    for (int i = 0, j = 0; i < m.length(); i += j)
    {
        j = 1;
        while (i + j < m.length() && isdigit(m[i + j]))
            j++;

        int n = j == 1 ? 1 : stoi(m.substr(i + 1, j));
        t[(int) m[i] - 65] += n * k;
    }
    
    return t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string p, q;
    int k;
    
    cin >> p >> k >> q;
    
    auto a = atomise(p, k);
    auto b = atomise(q);

    int c = __INT_MAX__;
    for (int i = 0; i < 26; i++)
    {
        if (a[i] < b[i])
        {
            c = 0;
            break;
        }

        if (a[i] > 0 && b[i] > 0)
            c = min(a[i] / b[i], c);
    }
        
    cout << c << '\n';
}