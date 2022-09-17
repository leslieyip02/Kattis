#include "heap.h"
#include <vector>
using namespace std;

vector<int> heap;

int getMax()
{
    return heap[0];
}

int getSize()
{
    return heap.size();
}

void insert(int element)
{
    int i = heap.size();
    heap.push_back(element);

    int p = (i - 1) / 2;
    while (heap[i] > heap[p])
    {
        int tmp = heap[p];
        heap[p] = heap[i];
        heap[i] = tmp;

        i = p;
        p = (i - 1) / 2;
    }
}

void maxHeapify(int p)
{
    int i = p;

    int l = 2 * p + 1;
    int r = 2 * (p + 1);

    if (l < heap.size() && heap[l] > heap[i])
        i = l;

    if (r < heap.size() && heap[r] > heap[i])
        i = r;

    if (i != p)
    {
        int tmp = heap[p];
        heap[p] = heap[i];
        heap[i] = tmp;

        maxHeapify(i);
    }
}

void removeMax()
{
    heap[0] = heap.back();
    heap.pop_back();

    maxHeapify(0);
}
