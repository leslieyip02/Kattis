#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

string ops[4] = { " * ", " / ", " + ", " - " };
// offset index by 257 since 256 is the max possible n
// 257 for *, 258 for /, 259 for + and 260 for -
int calculate(int a, int b, int op);
int reduce(int a, int b, int c);

int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int n;
        cin >> n;
        if (n > 256 || n < -60)
        {
            cout << "no solution" << endl;
            continue;
        }

        // brute force
        // there are only 4 ^ 3 possibilities
        for (int i = 257; i < 261; i++)
        {
            for (int j = 257; j < 261; j++)
            {
                for (int k = 257; k < 261; k++)
                {
                    if (reduce(i, j, k) == n)
                    {
                        cout << 4 << ops[i - 257]
                            << 4 << ops[j - 257]
                            << 4 << ops[k - 257]
                            << 4 << " = "
                            << n << endl;
                        goto next;
                    }
                }
            }
        }
        cout << "no solution" << endl;
        next:
            continue;
    }
    return 0;
}

int reduce(int a, int b, int c)
{
    // reduce the list of fours into 1 final output
    vector<int> eqn = { 4, c, 4, b, 4, a, 4 };
    // multiply and divide through equation first
    for (int i = eqn.size() - 1; i >= 0; i--)
    {
        for (int op = 257; op < 259; op++)
        {
            if (eqn[i] == op)
            {
                // continue if equation tries to divide by 0
                if (op == 258 && eqn[i - 1] == 0) 
                    return 1000001;
                eqn[i - 1] = calculate(eqn[i + 1], eqn[i - 1], op);
                eqn.erase(eqn.begin() + i, eqn.begin() + i + 2);

                /* for (int k = 0; k < eqn.size(); k++)
                    cout << eqn[k] << ", ";
                cout << endl; */

                if (eqn.size() == 1)
                    return eqn[0];
            }
        }
    }
    
    // go through equation and add / subtract in order
    for (int i = eqn.size() - 1; i >= 0; i--)
    {
        for (int op = 259; op < 261; op++)
        {
            if (eqn[i] == op)
            {
                eqn[i - 1] = calculate(eqn[i + 1], eqn[i - 1], op);
                eqn.erase(eqn.begin() + i, eqn.begin() + i + 2);

                /* for (int k = 0; k < eqn.size(); k++)
                    cout << eqn[k] << ", ";
                cout << endl; */

                if (eqn.size() == 1)
                    return eqn[0];
            }
        }
    }
    return eqn[0];
}

int calculate(int a, int b, int op)
{
    if (op == 257)
        return a * b;
    else if (op == 258)
        return (int) floor(a / b);
    else if (op == 259)
        return a + b;
    else
        return a - b;
}

