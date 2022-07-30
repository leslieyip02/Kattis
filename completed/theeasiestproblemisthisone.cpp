#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, p;
    int sum = -1;
    int np = -1;
    cin >> n;
    while (n != 0)
    {
        sum = 0;
        string nStr = to_string(n);
        for (int i = 0; i < nStr.length(); i++)
            sum += nStr[i] - '0';

        p = 10;
        do
        {
            np = 0;
            p++;

            string npStr = to_string(n * p);
            for (int i = 0; i < npStr.length(); i++)
                np += npStr[i] - '0';
        }
        while (np != sum);

        cout << p << endl;
        cin >> n;
    }

    return 0;
}