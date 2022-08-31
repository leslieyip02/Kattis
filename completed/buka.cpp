#include <iostream>
#include <string>
using namespace std;

string add(string a, string b)
{
    if (a.length() == b.length())
        a[0] = '2';
    else 
        a[a.length() - b.length()] = '1';
    return a;
}

string multiply(string a, string b)
{
    for (int i = 0; i < b.length() - 1; i++)
        a += '0';
    return a;
}

int main()
{
    string a, b, c, d, op;
    cin >> a >> op >> b;
    
    if (a.length() > b.length())
    {
        c = a;
        d = b;
    }
    else
    {
        c = b;
        d = a;
    }

    cout << (op == "+" ? add(c, d) : multiply(c, d)) << '\n';

    return 0;
}