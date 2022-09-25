#include <bits/stdc++.h>
using namespace std;

bool operator> (const pair<string, int> &a, const pair<string, int> &b)
{
    return a.second == b.second ? a.first < b.first : a.second > b.second;
}

struct heap
{
    vector<pair<string, int>> values;

    void insert(pair<string, int> p)
    {
        int i = values.size();
        int j = (i - 1) / 2;

        values.push_back(p);
        while (values[i] > values[j])
        {
            swap(values[i], values[j]);

            i = j;
            j = (i - 1) / 2;
        }
    }

    void heapify(int i)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int j = i;

        if (l < values.size() && 
            values[l] > values[j])
            j = l;

        if (r < values.size() && 
            values[r] > values[j])
            j = r;

        if (j != i)
        {
            swap(values[i], values[j]);
            heapify(j);
        }
    }

    pair<string, int> pop()
    {
        auto value = values.front();
        values.front() = values.back();
        values.pop_back();
        
        heapify(0);

        return value;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, nt, x, y, z;
    string u, t1, t2, t3;
    heap s1, s2, s3;

    cin >> n;
    nt = n / 3;

    while (n--)
    {
        cin >> u >> x >> y >> z;
        s1.insert(make_pair(u, x));
        s2.insert(make_pair(u, y));
        s3.insert(make_pair(u, z));
    }

    set<string> c;
    while (nt--)
    {
        t1 = s1.pop().first;
        while (c.find(t1) != c.end())
            t1 = s1.pop().first;
        c.insert(t1);
        
        t2 = s2.pop().first;
        while (c.find(t2) != c.end())
            t2 = s2.pop().first;
        c.insert(t2);

        t3 = s3.pop().first;
        while (c.find(t3) != c.end())
            t3 = s3.pop().first;
        c.insert(t3);

        string t[] { t1, t2, t3 };
        sort(t, t + 3);

        for (string m : t)
            cout << m << ' ';
        cout << '\n';
    }

    return 0;
}
