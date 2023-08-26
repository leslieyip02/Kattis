#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> a(N);
    vector<int> b(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> b[i];
    }

    map<int, int> m;
    for (int i = 0; i < N; i++)
    {
        m[a[i]]++;
        m[b[i]]--;
        if (!m[a[i]])
        {
            m.erase(a[i]);
        }
        if (!m[b[i]])
        {
            m.erase(b[i]);
        }

        cout << b[i] << ' ';
        if (m.empty() && i != N - 1)
        {
            cout << "# ";
        }
    }
    cout << endl;
    return 0;
}
