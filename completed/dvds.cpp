#include <iostream>
using namespace std;

int main()
{
    int k, n, dvd;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> n;

        int moves = 0, index = 1;
        for (int j = 1; j <= n; j++)
        {
            cin >> dvd;
            if (dvd != index)
                moves++;
            else
                index++;
        }
        
        cout << moves << endl;
    }

    return 0;
}