#include <iostream>
using namespace std;

int main()
{
    int n;
    string b;
    cin >> n >> b;

    for (int i = n; i > 1; i--)
    {
        cout << i << " bottles of " << b << " on the wall, "
             << i << " bottles of " << b
             << ".\nTake one down, pass it around, "
             << i - 1 << " bottle" << (i == 2 ? "" : "s") << " of "
             << b << " on the wall.\n\n";
    }

    cout << "1 bottle of " << b << " on the wall, 1 bottle of " << b
         << ".\nTake it down, pass it around, no more bottles of " << b << ".\n";

    return 0;
}