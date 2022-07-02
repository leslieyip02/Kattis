#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    int distance = 1000000;
    vector<int> next = vector<int>();
};

vector<node> movies = vector<node>();

void trace(int current, int d)
{
    movies[current].distance = d;
    for (int i : movies[current].next)
        if (movies[i].distance < 0 || movies[i].distance > movies[current].distance)
            trace(i, d + 1);
}

int main()
{
    int n, h, l;
    cin >> n >> h >> l;

    node root;
    for (int i = 0; i < n; i++)
        movies.push_back(node());

    for (int i = 0; i < h; i++)
    {
        int x;
        cin >> x;
        root.next.push_back(x);
    }
    movies.push_back(root);

    for (int i = 0; i < l; i++)
    {
        int a, b;
        cin >> a >> b;
        movies[a].next.push_back(b);
        movies[b].next.push_back(a);
    }

    trace(n, 0);

    int furthest = 0;
    int index = 0;
    for (int i = 0; i < n ; i++)
    {
        if (movies[i].distance > furthest)
        {
            furthest = movies[i].distance;
            index = i;
        }
    }

    cout << index << endl;

    return 0;
}