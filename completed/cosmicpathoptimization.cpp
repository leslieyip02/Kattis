#include <iostream>
using namespace std;

int main()
{
    int M;
    cin >> M;

    double S, T;
    S = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> T;
        S += T;
    }
    cout << (int) S / M << '\n';
    return 0;
}
