#include <iostream>
using namespace std;

int main(void)
{
    string ln;
    while (getline(cin, ln))
    {
        int n = stoi(ln);
        getline(cin, ln);

        for (char c : ln)
        {
            // 33 - 42 (! to *)
            // 91 - 93 ([ to ])
            int a = (int) c;
            if ((33 <= a && a <= 42) ||
                (91 <= a && a <= 93))
            {
                int m = 0;
                for (int i = 0; i < n; i++)
                    m += 1 << i;

                cout << string(m, '\\');
            }

            cout << c;
        }
        
        cout << '\n';
    }

    return 0;
}