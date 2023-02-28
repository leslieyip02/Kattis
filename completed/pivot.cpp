#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> A;
    A.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    // largest on lhs < smallest on rhs
    int hi = 0;
    set<int> lo(A.begin(), A.end());
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        hi = max(A[i], hi);

        if (hi <= A[i] && hi <= *lo.begin())
        {
            c++;
        }

        lo.erase(A[i]);
    }

    cout << c << '\n';

    return 0;
}