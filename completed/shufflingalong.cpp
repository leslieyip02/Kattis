#include <bits/stdc++.h>
using namespace std;

int out_shuffle(vector<int> x)
{
    int h = ceil(x.size() / 2.0);
    vector<int> y(x.size());
    for (int i = 0; i < x.size(); i += 2)
    {
        y[i] = x[i / 2];
        y[i + 1] = x[i / 2 + h];
    }
    
    return 1 + (is_sorted(y.begin(), y.end()) ? 0 : out_shuffle(y));
}

int in_shuffle(vector<int> x)
{
    int h = floor(x.size() / 2.0);
    vector<int> y(x.size());
    for (int i = 0; i < x.size(); i += 2)
    {
        y[i] = x[i / 2 + h];
        y[i + 1] = x[i / 2];
    }

    return 1 + (is_sorted(y.begin(), y.end()) ? 0 : in_shuffle(y));
}

int main()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> d(n);
    iota(d.begin(), d.end(), 1);
    cout << (s == "out" ? out_shuffle(d) : in_shuffle(d))<< '\n';

    return 0;
}