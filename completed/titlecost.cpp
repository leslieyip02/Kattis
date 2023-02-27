#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string s;
    double c;

    cin >> s >> c;
    cout << setprecision(10) << min((double) s.size(), c) << '\n';

    return 0;
}