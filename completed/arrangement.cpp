#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int r = m % n;
    for (int i = 0; i < r; i++)
    {
        for (int k = 0; k < m / n + 1; k++)
            cout << '*';
        cout << endl;
    }   

    for (int i = 0; i < n - r; i++) 
    {
        for (int k = 0; k < m / n; k++)
            cout << '*';
        cout << endl;
    }  

    return 0;
}