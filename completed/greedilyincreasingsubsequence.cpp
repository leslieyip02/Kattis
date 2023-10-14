#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, a;
    vector<int> A;

    cin >> N;
    while (N--)
    {
        cin >> a;
        if (A.empty() || a > A.back())
        {
            A.push_back(a);
        }
    }

    cout << A.size() << '\n';
    for (auto a : A)
    {
        cout << a << ' ';
    }
    cout << '\n';
    return 0;
}
