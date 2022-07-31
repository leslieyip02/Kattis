#include <iostream>
#include <string>
using namespace std;

int main()
{
    int l, h;
    cin >> l >> h;

    int cnt = 0;
    for (int i = l; i <= h; i++)
    {
        string c = to_string(i);

        for (int j = 0; j < c.length(); j++)
        {
            for (int k = j + 1; k < c.length(); k++)
                if (c[k] == c[j])
                    goto next;

            if (c[j] == '0' || i % (int) (c[j] - '0') != 0)
                goto next;
        }
        cnt++;

        next:
            continue;
    }

    cout << cnt << endl;

    return 0;
}