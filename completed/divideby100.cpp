#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n, m;
    cin >> n >> m;

    if (n.length() < m.length())
        n = string(m.length() - n.length(), '0') + n;

    string frt = n.substr(0, n.length() - (m.length() - 1));
    string end = n.substr(n.length() - (m.length() - 1));

    m = frt + '.' + end;
    while (m.back() == '0')
        m = m.substr(0, m.length() - 1);

    if (m.back() == '.')
        m = m.substr(0, m.length() - 1);

    cout << m << '\n';

    return 0;
}