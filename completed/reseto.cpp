#include <iostream>
#include <vector>
using namespace std;

int cross_out(int n, int k)
{
    vector<bool> p(n + 1, true);
    p[0] = p[1] = false;

    for (int i = 2; i <= n; i++)
    {
        if (p[i])
        {
            int j = i;
            while (j <= n)
            {
                if (p[j])
                {
                    p[j] = false;

                    if (--k <= 0)
                        return j;
                }

                j += i;
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    cout << cross_out(n, k) << '\n';    

    return 0;
}