#include <iostream>
using namespace std;

int main()
{
    int r;
    cin >> r;

    int hi = r;
    int lo = 0;
    int mid = r / 2;
    string res;

    cout << mid << '\n' << flush;
    cin >> res;

    int i = 2;
    while (res != "exact")
    {
        if (res == "less")
            hi = mid - 1;
        else
            lo = mid + 1;

        mid = (hi + lo) / 2;
        cout << mid * i++ << '\n' << flush;
        cin >> res;
    }

    return 0;
}