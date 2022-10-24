#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a[n + 2];
    a[0] = a[n + 1] = __INT_MAX__;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    // store subsequence
    vector<int> ss;
    ss.push_back(a[0]);

    unsigned long long s = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        // if current value greater than the last value in the subsequence,
        // reduce the subsequence and continue with the current value
        while (a[i] >= ss.back())
        {
            // build subsequence until aᵢ₋₁ ≥ aᵢ ≤ aᵢ₊₁
            int c = min(a[i], *(++ss.rbegin()));
            
            // once the other end of the sequence has been reached,
            // and the current subsequence has been reduced,
            if (c == __INT_MAX__)
                break;

            s += c;
            ss.pop_back();
        }

        ss.push_back(a[i]);
    }

    cout << s << '\n';

    return 0;
}