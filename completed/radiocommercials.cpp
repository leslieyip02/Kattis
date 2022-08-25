#include <iostream>
using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;

    int s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int maxSum = -2000;
    int currentSum = 0;
    for (int i = 0; i < n; i++)
    {
        currentSum += s[i] - p;
        if (maxSum < currentSum)
            maxSum = currentSum;
        if (currentSum < 0)
            currentSum = 0;
    }

    cout << maxSum << endl;

    return 0;
}