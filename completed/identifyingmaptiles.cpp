#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int l = s.length();
    int x = 0;
    int y = 0;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '1' || s[i] == '3')
            x += pow(2, l - 1 - i);
        if (s[i] == '2' || s[i] == '3')
            y += pow(2, l - 1 - i);
    }
    
    cout << l << " " << x << " " << y << endl;
    return 0;
}