#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, lph;
    cin >> n >> lph;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    int ok = 0;
    int sum = 0;
    int max = lph * 5;
    while (ok < n && sum + p[ok] <= max)
    {
        sum += p[ok];
        ok++;
    }
    printf("%i\n", ok);
    return 0;
}