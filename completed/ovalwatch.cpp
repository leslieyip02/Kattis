#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define pii pair<int, int>

int main()
{
    int N, K;
    cin >> N >> K;
    vector<pii> legs(K);
    for (int i = 0; i < K; i++)
    {
        cin >> legs[i].first >> legs[i].second;
    }
    sort(legs.begin(), legs.end(), [](const pii& a, const pii& b)
    {
        return a.second > b.second;
    });

    vector<int> p(N);
    for (int i = 0; i < N; i++)
    {
        p[i] = i;
    }

    for (pii leg : legs)
    {
        int tmp = p[leg.first];
        p[leg.first] = p[leg.first + 1];
        p[leg.first + 1] = tmp;
    }
    for (int i : p)
    {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}