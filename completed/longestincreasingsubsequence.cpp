#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int nums[n];
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        int sequence[n + 1] = { 0 };
        int previous[n] = { 0 };
        int lower, middle, upper, new_length;
        int current_length = 0;
        for (int i = 0; i < n; i++)
        {
            lower = 1;
            upper = current_length;

            while (lower <= upper)
            {
                middle = ceil((lower + upper) / 2.0);
                if (nums[sequence[middle]] < nums[i])
                    lower = middle + 1;
                else
                    upper = middle - 1;
            }
            new_length = lower;

            previous[i] = sequence[new_length - 1];
            sequence[new_length] = i;

            if (new_length > current_length)
                current_length = new_length;
        }

        int longest_sequence[current_length];
        int current_index = sequence[current_length];
        for (int i = current_length - 1; i >= 0; i--)
        {
            longest_sequence[i] = current_index;
            current_index = previous[current_index];
        }

        cout << current_length << endl;
        for (int i = 0; i < current_length; i++)
            cout << longest_sequence[i] << " ";
        cout << endl;
    }

    return 0;
}