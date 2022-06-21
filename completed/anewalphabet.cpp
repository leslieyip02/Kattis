#include <iostream>
#include <string>
using namespace std;

string alphabets[] = { "@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1", "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z", "$", "']['", "|_|", "\\/", "\\/\\/", "}{", "`/", "2" };

int main()
{
    string str;
    getline(cin, str);

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        if (islower(c)) 
          cout << alphabets[(int) c - 97];
        else if (isupper(c)) 
          cout << alphabets[(int) c - 65];
        else
          cout << c;
    }
    cout << endl;

    return 0;
}


