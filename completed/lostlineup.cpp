#include <iostream>
using namespace std;

int main()
{
    int n, gap;
    int line[100];

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> gap;
        line[gap] = i + 2;
    }

    cout << 1 << " ";
    for (int i = 0; i < n - 1; i++)
        cout << line[i] << " ";
    cout << endl;

    return 0;
}