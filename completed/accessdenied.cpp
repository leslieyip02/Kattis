#include <iostream>
#include <string>
using namespace std;

string alphanumeric = "BCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

int main()
{
    string res, guess = "A";
    int len = 0, guess_index = 0, alphanumeric_index = 0;

    cout << guess << endl;
    getline(cin, res);
    
    while (res != "ACCESS GRANTED")
    {
        int t, digits;
        digits = res.find(" ", 15) - 15;
        t = stoi(res.substr(15, digits));

        // wrong length
        // 1 ms for if, 3 ms to compare, 1 ms to return if wrong
        if (t == 5)
        {
            guess.append("A");
        }
        // correct length
        else
        {
            // 4 ms to skip length check
            // for each letter,
            // 1 ms for for, 1 ms to set i or next i, 
            // 3 ms to check if i < length,
            // 1 ms for if, 3 ms to compare
            // 1 ms to return if wrong 
            int current = (t - 5) / 9 - 1;
            if (current > guess_index)
            {
                guess_index = current;
                alphanumeric_index = 0;
            }
            guess[guess_index] = alphanumeric[alphanumeric_index];
            alphanumeric_index++;
        }
        
        cout << guess << endl;
        getline(cin, res);
    }

    return 0;
}