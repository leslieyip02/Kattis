#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while (true)
    {
        string nStr = to_string(n);
        int digitSum = 0;
        for (int i = 0; i < nStr.length(); i++)
            digitSum += (int) nStr[i] - '0';

        if (n % digitSum == 0)
            break;

        n++;
    }

    cout << n << endl;
    return 0;
}