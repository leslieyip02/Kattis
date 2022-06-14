#include <iostream>
#include <string>
using namespace std;

int main()
{
    string spam;
    cin >> spam;

    double white, lower, upper, symbol;
    white = lower = upper = symbol = 0;
    for (int i = 0; i < spam.length(); i++)
    {
        char current = spam[i];
        if ((int) current == 95) { white++; }
        else if (islower(current)) { lower++; }
        else if (isupper(current)) { upper++; }
        else { symbol++; }
    }
    cout << white / spam.length() << endl;
    cout << lower / spam.length() << endl;
    cout << upper / spam.length() << endl;
    cout << symbol / spam.length() << endl;

    return 0;
}