#include <iostream>
#include <map>
using namespace std;

char notes[] = { 'G', 'F', 'E', 'D', 'C', 'B', 'A', 
    'g', 'f', 'e', 'd', 'c', 'b', 'a' };
char lines[] = { 'F', 'D', 'B', 'g', 'e', 'a' };
char empties[] = { 'G', 'E', 'C', 'A', 'f', 'd', 'c', 'b' };
map<char, string> staff;

int main()
{
    int n, l;
    cin >> n;

    for (char note : notes)
        staff.insert({ note, "" });

    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        
        l = 1;
        if (s.length() > 1)
            l = (int) (s[1] - '0');

        for (char note : lines)
        {
            if (note != s[0])
                staff[note] += string(l + 1, '-');
            else
                staff[note] += string(l, '*') + '-';
        }
            
        for (char note : empties)
        {
            if (note != s[0])
                staff[note] += string(l + 1, ' ');
            else
                staff[note] += string(l, '*') + ' ';
        }
    }

    for (char note : notes)
        cout << note << ": " << staff[note].substr(0, staff[note].length() - 1) << endl;

    return 0;
}