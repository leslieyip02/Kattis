#include <iostream>
#include <string>
using namespace std;

int main()
{
    string ln;
    getline(cin, ln);
    int n = stoi(ln);

    while (n--)
    {
        string phr;
        getline(cin, phr);
        
        bool a[26] = { false };
        for (char l : phr)
            if (isalpha(l))
                a[(int) l - (isupper(l) ? 65 : 97)] = true;
        
        bool pan = true;
        for (bool l : a)
        {
            if (!l)
            {
                pan = false;
                break;
            }
        }
        
        if (pan)
        {
            cout << "pangram" << endl;
        }
        else
        {
            cout << "missing ";
            for (int i = 0; i < 26; i++)
                if (!a[i])
                    cout << (char) (i + 97);
            cout << endl;
        }
    }

    return 0;
}