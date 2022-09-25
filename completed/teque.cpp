#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    string s;

    deque<int> front, back;
    int mid = -1;
    
    int len = 0;
    
    cin >> n;
    while (n--)
    {
        cin >> s >> x;
        if (s == "push_back")
        {
            if (mid == -1)
            {
                mid = x;
            }
            else
            {
                if (len % 2 == 1 && !back.empty())
                {
                    front.push_back(mid);
                    mid = back.front();
                    back.pop_front();
                }
                
                back.push_back(x);
            }
            
            len++;
        }
        else if (s == "push_front")
        {
            if (mid == -1)
            {
                mid = x;
            }
            else
            {
                if (len % 2 == 0 && !front.empty())
                {
                    back.push_front(mid);
                    mid = front.back();
                    front.pop_back();
                }
                
                front.push_front(x);
            }
            
            len++;
        }
        else if (s == "push_middle")
        {
            if (mid != -1)
            {
                if (len % 2 == 1)
                    front.push_back(mid);
                else
                    back.push_front(mid);
            }
            
            mid = x;
            len++;
        }
        else
        {
            if (x < front.size())
                cout << front[x] << '\n';
            else if (x == front.size())
                cout << mid << '\n';
            else 
                cout << back[x - front.size() - 1] << '\n';
        }
    }
    
    return 0;
}
