#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void append(deque<string> &msg, vector<char> &cv, bool frt)
{
    string ss(cv.begin(), cv.end());
                    
    if (frt)
        msg.push_front(ss);
    else
        msg.push_back(ss);

    cv.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    cin.ignore(1, '\n');

    while (t--)
    {
        deque<string> msg;
        vector<char> cv;
        bool frt = false;
        
        string ln;
        getline(cin, ln);
        for (char c : ln)
        {
            if (c == ']' || c == '[')
            {
                if (!cv.empty())
                    append(msg, cv, frt);

                frt = c == '[';
            }
            else if (c == '<')
            {
                if (!cv.empty())
                {
                    cv.pop_back();
                }
                else if (!frt && !msg.empty())
                {
                    msg.back() = msg.back().substr(0, msg.back().length() - 1);
                    if (msg.back().empty())
                        msg.pop_back();
                }
            }
            else
            {
                cv.push_back(c);
            }   
        }

        if (!cv.empty())
            append(msg, cv, frt);

        for (string s : msg)
            cout << s;
        cout << '\n';
    }

    return 0;
}