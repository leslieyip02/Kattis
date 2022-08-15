#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

struct runner 
{
    string name;
    double a;
    double b;
};

int main()
{
    int n;
    double a, b;

    cin >> n;
    runner runners[n];
    for (int i = 0; i < n; i++)
    {
        runner ri;
        cin >> ri.name >> ri.a >> ri.b;
        runners[i] = ri;
    }

    sort(runners, runners + n, [](auto &r1, auto &r2)
    {
        return r1.b < r2.b;
    });

    double t0 = 80.0;
    string team0[4];
    for (int i = 0; i < n; i++)
    {
        double ti = runners[i].a;
        string teami[] = { runners[i].name, "", "", "" };
        
        int j = 0;
        int k = 1;
        while (k < 4)
        {
            if (j == i)
                goto next;

            ti += runners[j].b;
            teami[k] = runners[j].name;
            k++;
            
            next:
                j++;
        }

        if (ti < t0)
        {
            t0 = ti;
            copy(teami, teami + 4, team0);
        }
    }

    cout << t0 << endl;
    for (string name : team0)
        cout << name << endl;

    return 0;
}