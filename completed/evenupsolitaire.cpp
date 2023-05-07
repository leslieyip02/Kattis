#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;

    vector<int> c;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (!c.empty() && c.back() % 2 == x % 2)
        {
            c.pop_back();
        }
        else
        {
            c.push_back(x);
        }
    }

    cout << c.size() << '\n';

    return 0;
}