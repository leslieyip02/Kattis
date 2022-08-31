#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, s0, s, x, c = 0;
    string o;
    
    cin >> n >> s0;
    s = s0;
    while (n--)
    {
        cin >> o;
        x = (int) o[0] - '0';
        if (o.length() > 1)
            x++;
            
        if (x > s)
        {
            s = s0;
            c++;
        }
        s -= x;
    }

    cout << c << '\n';

    return 0;
}