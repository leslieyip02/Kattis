#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int Q, k;
    cin >> Q;

    while (Q--)
    {
        cin >> k;
        vector<int> m(k, 0);

        int f0 = 1;
        int f1 = 1;
        int f2 = 2;
        for (int i = 2; true; i++)
        {
            f2 = (f0 % k + f1 % k) % k;
            if (m[f2])
            {
                cout << m[f2] << '\n';
                break;
            }

            m[f2] = i;
            f0 = f1;
            f1 = f2;
        }
    }

    return 0;
}