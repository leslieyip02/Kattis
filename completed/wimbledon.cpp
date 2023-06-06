#include <iostream>
#include <vector>
using namespace std;

#define ull unsigned long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    ull p = 0;
    ull sum_of_a = 0;
    vector<int> a(N);
    vector<int> b(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i] >> b[i];

        if (a[i] > 0)
        {
            if (p == 0)
            {
                p = 1;
            }

            p *= a[i];
            sum_of_a += a[i];
        }
    }

    // b1 * (a2 * a3 + a2 * a4 + ...) + b2(a1 * a3 + a1 * a4 + ...) + ...

    ull current_sum = sum_of_a;
    ull product_of_a_pairs = 0;
    for (int i = 0; i < N; i++)
    {
        current_sum -= a[i];
        product_of_a_pairs += a[i] * current_sum;
    }

    ull m = 0;
    for (int i = 0; i < N; i++)
    {
        m += b[i] * (product_of_a_pairs - a[i] * (sum_of_a - a[i]));
    }

    cout << m << '\n';

    return 0;
}