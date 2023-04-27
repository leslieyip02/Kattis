#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n, m, a, b, c;

    cin >> n >> m;

    deque<int> q;

    b = 0;
    while (n--)
    {
        cin >> a;
        q.push_back(a);

        if (q.size() < m)
        {
            continue;
        }
        
        c = 0;
        for (int d : q)
        {
            c += d % 2;
        }

        if (c <= m - 2)
        {
            b++;
        }

        q.pop_front();
    }

    cout << b << '\n';

    return 0;
}