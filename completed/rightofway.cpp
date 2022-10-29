#include <iostream>
#include <map>
using namespace std;

int main()
{
    string a, b, c;
    cin >> a >> b >> c;

    map<string, string> opp = {
        { "North", "South" },
        { "South", "North" },
        { "East" , "West"  },
        { "West" , "East"  }
    };

    map<string, string> right = {
        { "North", "West"  },
        { "South", "East"  },
        { "East" , "North" },
        { "West" , "South" }
    };

    bool give = false;
    if (b == opp[a])
        give = c == right[a];
    else if (b != right[a])
        give = c == opp[a] || c == right[a];

    cout << (give ? "Yes" : "No") << '\n';

    return 0;
}