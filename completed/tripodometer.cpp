#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n;

    y = 0;
    set<int> d;    
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        y += x;
        d.insert(x);
    }

    cout << d.size() << '\n';
    for (auto itr = d.rbegin(); itr != d.rend(); itr++)
        cout << y - *itr << " ";

    return 0;
}