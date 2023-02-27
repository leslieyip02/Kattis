#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<string> intersections;
    map<string, int> intersection_indices;
    
    intersections.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> intersections[i];
        intersection_indices.insert({ intersections[i], i });
    }

    string from, to;
    int from_index, to_index;
    while (q--)
    {
        cin >> from >> to;
        from_index = intersection_indices[from];
        to_index = intersection_indices[to];
        cout << abs(from_index - to_index) - 1 << '\n';
    }

    return 0;
}