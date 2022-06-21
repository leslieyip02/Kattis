#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    if (t == 1)
    {
        cout << 7 << endl;
        return 0;
    }
    else if (t == 2)
    {
        int a0, a1;
        cin >> a0 >> a1;
        if (a0 > a1)
            cout << "Bigger" << endl;
        else if (a0 < a1)
            cout << "Smaller" << endl;
        else
            cout << "Equal" << endl;
        return 0;
    }
    else if (t == 3)
    {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        cout << a[1] << endl;
        return 0;
    }
    else if (t == 4)
    {
        int a;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            sum += a;
        }
        cout << sum << endl;
        return 0;
    }
    else if (t == 5)
    {
        int a;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (a % 2 == 0)
                sum += a;
        }
        cout << sum << endl;
        return 0;
    }
    else if (t == 6)
    {
        int a;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            cout << (char) (a % 26 + 97);
        }
        cout << endl;
        return 0;
    }
    else if (t == 7)
    {
        int visitors[n];
        int a;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            visitors[i] = a;
        }

        int i = 0;
        while (true)
        {
            if (i >= n)
            {
                cout << "Out" << endl;
                return 0;
            }
            else if (i == n - 1)
            {
                cout << "Done" << endl;
                return 0;
            }
            else if (visitors[i] == -1)
            {
                cout << "Cyclic" << endl;
                return 0;
            }
            else
            {
                int prev_index = i;
                i = visitors[i];
                visitors[prev_index] = -1;
            }
        }
    }

    return 0;
}