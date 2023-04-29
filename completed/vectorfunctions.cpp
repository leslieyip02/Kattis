#include "vectorfunctions.h"

void backwards(std::vector<int> &vec)
{
    std::vector<int> v;

    while (!vec.empty())
    {
        v.push_back(vec.back());
        vec.pop_back();
    }

    for (auto i : v)
    {
        vec.push_back(i);
    }
}

std::vector<int> everyOther(const std::vector<int> &vec)
{
    std::vector<int> v;
    for (int i = 0; i < vec.size(); i += 2)
    {
        v.push_back(vec[i]);
    }

    return v;
}

int smallest(const std::vector<int> &vec)
{
    int m = 3000;
    for (auto i : vec)
    {
        if (i < m)
        {
            m = i;
        }
    }

    return m;
}

int sum(const std::vector<int> &vec)
{
    int s = 0;
    for (auto i : vec)
    {
        s += i;
    }

    return s;
}

int veryOdd(const std::vector<int> &suchVector)
{
    int n = 0;
    for (int i = 1; i < suchVector.size(); i += 2)
    {
        if (suchVector[i] % 2 != 0)
        {
            n++;
        }
    }

    return n;
}
