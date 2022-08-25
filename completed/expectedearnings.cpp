#include <iostream>
using namespace std;

int main()
{
    int n, k;
    double p;
    cin >> n >> k >> p;

    cout << (p * n - k < 0 ? "spela" : "spela inte!") << endl;

    return 0;
}