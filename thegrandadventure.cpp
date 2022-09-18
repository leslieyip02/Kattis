#include <iostream>
#include <vector>
using namespace std;

vector<char> inventory;

bool give(char i)
{
    while (inventory.size() > 0 && inventory.back() != i)
        inventory.pop_back();

    if (inventory.size() == 0)
        return false;
    
    inventory.pop_back();
    return true;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        string journey;
        cin >> journey;

        inventory.clear();
        bool completable = true;
        for (char i : journey)
        {
            if (i == '.')
                continue;

            if (i == '$' || i == '|' || i == '*')
                inventory.push_back(i);

            if ((i == 'b' && !give('$')) ||
                (i == 't' && !give('|')) ||
                (i == 'j' && !give('*')))
            {
                completable = false;
                break;
            }
        }

        cout << (completable && inventory.empty() ? "YES\n" : "NO\n");
    }

    return 0;
}