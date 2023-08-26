#include <iostream>
#include <vector>
#include <algorithm>
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
        b[i] = a[i];
    }
    sort(b.begin(), b.end());

    int c = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i] != b[i])
        {
            c++;
        }
    }
    cout << c << '\n';
    return 0;
}
