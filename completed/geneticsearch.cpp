#include <iostream>
#include <vector>
#include <set>
using namespace std;

// longest proper suffixes (LPS)
// i.e. suffix that matches the prefix of the pattern
vector<int> compute_lps(string pat)
{
    // store length of LPS at each index
    vector<int> lps(pat.length(), 0);
    lps[0] = 0;

    // length of prefix (count from start)
    int i = 0;
    // index of current character
    int j = 1;

    while (j < pat.length())
    {
        // if the characters match, advance both counters
        if (pat[i] == pat[j])
        {
            i++;
            lps[j] = i;
            j++;
        }
        // if they don't match,
        else
        {
            // if the current prefix is not empty,
            // then try to shorten the prefix 
            // to check if there is a suitable shorter prefix
            if (i != 0)
            {
                i = lps[i - 1];
            }
            // if not, advance the character index and move on
            else
            {
                lps[j] = 0;
                j++;
            }
        }
    }

    return lps;
}

// count number of times pat occurs in str
int count_occurences(string pat, string str)
{
    int occurences = 0;

    vector<int> lps = compute_lps(pat);

    // index for pattern
    int i = 0;
    // index for search str
    int j = 0;

    while ((pat.length() - i) <= (str.length() - j))
    {
        if (pat[i] == str[j])
        {
            i++;
            j++;
        }

        // if the length is equal to the length, then a match is found
        // move the search index up based on the LPS
        if (i == pat.length())
        {
            occurences++;
            i = lps[i - 1];
            continue;
        }

        // if the characters at the next indices don't match,
        // either advance the search index, or advance the pattern index
        if (j < str.length() && pat[i] != str[j])
        {
            if (i != 0)
                i = lps[i - 1];
            else
                j++;
        }
    }

    return occurences;
}

int main()
{
    string s, l;
    cin >> s;

    while (s != "0")
    {
        cin >> l;

        // type 1: S without changes
        int t1 = count_occurences(s, l);

        // type 2: unique strings by deleting one char from S
        int t2 = 0;
        set<string> shortened;
        for (int i = 0; i < s.length(); i++)
        {
            string shorter = s.substr();
            shorter.erase(i, 1);
            shortened.insert(shorter);
        }

        for (string x : shortened)
            t2 += count_occurences(x, l);

        // type 3: unique strings by adding one char
        int t3 = 0;
        set<string> lengthened;
        for (int i = 0; i <= s.length(); i++)
        {
            for (string c : { "A", "G", "C", "T" })
            {
                string longer = s.substr();
                longer.insert(i, c);
                lengthened.insert(longer);
            }
        }

        for (string x : lengthened)
            t3 += count_occurences(x, l);

        cout << t1 << ' ' << t2 << ' ' << t3 << '\n';

        cin >> s;
    }

    return 0;
}