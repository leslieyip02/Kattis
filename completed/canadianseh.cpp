#include <iostream>
using namespace std;

int main()
{
    string s;
    while (cin >> s) {}

    cout << (s == "eh?" ? "Canadian" : "Imposter") << "!\n";

    return 0;
}