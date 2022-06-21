#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main()
{
    int n, t, num;
    cin >> n >> t;

    if (t < 3)
    {
        // need to remove duplicates
        unordered_set<int> nums;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            nums.insert(num);
        }

        if (t == 1)
        {
            for (int num : nums)
            {
                if (num > 7777)
                    continue;
                    
                if (nums.find(7777 - num) != nums.end())
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
            cout << "No" << endl;
            return 0;
        }
        else
        {
            if (nums.size() == n)
                cout << "Unique" << endl;
            else
                cout << "Contains duplicate" << endl;
            return 0;
        }
    }
    else
    {
        // keep duplicates
        int nums[n];
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        sort(nums, nums + n);
        
        if (t == 3)
        {
            int current_num = nums[0];
            int current_count = 0;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == current_num)
                {
                    current_count++;
                    if (current_count > n / 2)
                    {
                        cout << current_num << endl;
                        return 0;
                    }
                }
                else
                {
                    current_num = nums[i];
                    current_count = 1;
                }
            }
            cout << -1 << endl;
            return 0;
        }
        else if (t == 4)
        {
            if (n % 2 == 0)
                cout << nums[n / 2 - 1] << " ";
            cout << nums[n / 2] << endl;
            return 0;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (nums[i] > 999)
                {
                    cout << endl;
                    return 0;
                }
                else if (nums[i] >= 100)
                {
                    cout << nums[i] << " ";
                }
            }
            cout << endl;
            return 0;
        }
    }

    return 0;
}