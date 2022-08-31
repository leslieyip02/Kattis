#include <iostream>
#include <string>
using namespace std;

int main()
{
    int p1, p2;
    string s0, s1, s2, r0, r1, r2;
    cin >> s0 >> s1 >> r0 >> r1;
    while (s0 != "0")
    {
        s2 = s0 > s1 ? s0 + s1 : s1 + s0;
        r2 = r0 > r1 ? r0 + r1 : r1 + r0;

        p1 = s2 == "21" ? 1000 : stoi(s2) * (s0 == s1 ? 10 : 1);
        p2 = r2 == "21" ? 1000 : stoi(r2) * (r0 == r1 ? 10 : 1);

        if (p1 == p2)
            cout << "Tie.\n";
        else
            cout << "Player " << (p1 > p2 ? 1 : 2) << " wins.\n";

        cin >> s0 >> s1 >> r0 >> r1;
    }

    return 0;
}