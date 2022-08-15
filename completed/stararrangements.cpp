#include <iostream>
using namespace std;

int main()
{
    int s, r;
    cin >> s;
    cout << s << ":\n";
    
    int a = 2;
    int b = 1;
    while (a + b <= s)
    {
        r = s % (a + b);
        if (r == 0 || r == a)
            cout << a << "," << b << endl;

        if (a == b)
            a++;
        else 
            b++;
    }

    return 0;
}