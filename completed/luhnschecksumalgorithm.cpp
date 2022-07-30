#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string n;
        cin >> n;

        int sum = 0;
        for (int j = 1; j <= n.length(); j++)
        {
            int d = (int) (n[n.length() - j] - '0');
            if (j % 2 == 0)
                sum += d >= 5 ? d * 2 - 9 : d * 2;
            else
                sum += d;
        }

        cout << (sum % 10 == 0 ? "PASS" : "FAIL") << endl;
    }
    

    return 0;
}