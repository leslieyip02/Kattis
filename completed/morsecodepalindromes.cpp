#include <iostream>
#include <ctype.h>
using namespace std;

string a[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
    "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

string d[] = { "-----", ".----", "..---", "...--", "....-", ".....", 
    "-....", "--...", "---..", "----." };

bool isPalindrome(string s)
{
    if (s.empty())
        return false;

    for (int i = 0; i < s.length() / 2; i++)
        if (s[i] != s[s.length() - i - 1])
            return false;

    return true;
}

int main()
{
    string s, t;
    getline(cin, s);

    t = "";
    for (char c : s)
    {
        if (isalpha(c))
            t += a[(int) toupper(c) - 65];

        else if (isdigit(c))
            t += d[(int) c - '0'];
    }

    cout << isPalindrome(t) << '\n';

    return 0;
}
