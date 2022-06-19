#include <iostream>
#include <vector>
using namespace std;

struct chapter {
    bool culminating = true;
    bool read = false;
    int pages;
    vector<int> dependencies{};
};

// recursively check the page count
int read(chapter &current, chapter book[]);

int main()
{
    int n, m;
    cin >> n >> m;

    // add chapters
    chapter book[n];
    for (int i = 0; i < n; i++)
    {
        chapter current;
        cin >> current.pages;
        book[i] = current;
    }

    // add dependencies
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        book[a - 1].culminating = false;
        book[b - 1].dependencies.push_back(a);
    }

    // go through book to look for min
    int min_pages = -1;
    for (int i = 0; i < n; i++)
    {
        if (book[i].culminating)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (book[j].culminating)
                {
                    int sum = read(book[i], book) + read(book[j], book);
                    if (min_pages == -1)
                        min_pages = sum;
                    else
                        min_pages = min(min_pages, sum);

                    // reset and unread all books
                    for (int k = 0; k < n; k++)
                        book[k].read = false;
                }
            }
        }
    }

    cout << min_pages << endl;
    return 0;
}

int read(chapter &current, chapter book[])
{
    if (current.read) return 0;
    
    int sum = current.pages;
    current.read = true;
    
    for (int i = 0; i < current.dependencies.size(); i++)
        sum += read(book[current.dependencies[i] - 1], book);
    
    return sum;
}