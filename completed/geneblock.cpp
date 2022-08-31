#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t, i;
    string n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        i = 1;
        while (n[n.length() - 1] != '7' && i <= 10)
        {
            n = to_string(stoi(n) - 7);
            i++;
        }
        
        if (i > 10 || stoi(n) < 0)
            i = -1;
        cout << i << '\n';
    }

    return 0;
}