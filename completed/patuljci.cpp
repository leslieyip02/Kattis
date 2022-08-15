#include <iostream>
using namespace std;

int main()
{
    int d[9];
    for (int i = 0; i < 9; i++)
        cin >> d[i];

    for (int i = 0; i < 8; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            int sum = 0;
            for (int k = 0; k < 9; k++)
            {
                if (k == i || k == j)
                    continue;
                else
                    sum += d[k];
            }

            if (sum == 100)
            {
                for (int k = 0; k < 9; k++)
                {
                    if (k == i || k == j)
                        continue;
                    else
                        cout << d[k] << endl;
                }

                return 0;
            }
        }
    }

    return 0;
}