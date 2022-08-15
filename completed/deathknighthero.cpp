#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    int c = 0;
    string k;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if (k.find("CD") == string::npos)
            c++;
    }
    cout << c << endl;

    return 0;
}