#include <iostream>
using namespace std;

int main()
{
    string k, d;
    int n;
    cin >> k >> n;
    while (n--)
    {
        cin >> d;
        bool ok = d.length() >= 4 && (d.find(k[0]) != string::npos);

        for (char a : d)
        {
            if (!ok)
                break;

            if (k.find(a) == string::npos)
                ok = false;
        }
        
        if (ok)
            cout << d << '\n';
    }

    return 0;
}