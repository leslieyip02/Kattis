#include <bits/stdc++.h>
using namespace std;

// store all powers from 0 - 9 for loookup
int powers[10][10] = {
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 },
    { 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683 },
    { 1, 4, 16, 64, 256, 1024, 4096, 16384, 65536, 262144 },
    { 1, 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125 },
    { 1, 6, 36, 216, 1296, 7776, 46656, 279936, 1679616, 10077696 },
    { 1, 7, 49, 343, 2401, 16807, 117649, 823543, 5764801, 40353607 },
    { 1, 8, 64, 512, 4096, 32768, 262144, 2097152, 16777216, 134217728 },
    { 1, 9, 81, 729, 6561, 59049, 531441, 4782969, 43046721, 387420489 }
};

vector<int> a;

vector<int> decrypt(int v, int w)
{
    if (w > a.size() || v < 0)
        return vector<int>();

    // ending digits
    int ed0, edi;
    ed0 = v % 10;

    // current digit of a
    int d = a[a.size() - w];

    // current power
    int p;
    for (int i = 0; i < 32; i++)
    {
        p = i < 10 ? powers[d][i] : (int) pow(d, i);
        
        if (p == v && w == a.size())
            return vector<int>(1, i);
        
        if (p >= v)
            break;

        edi = p % 10;
        if (ed0 == edi)
        {
            auto key = decrypt((v - p) / 10, w + 1);
            if (!key.empty())
            {
                key.push_back(i);
                return key;
            }
        }
    }

    return vector<int>();
}

int main()
{
    string s;
    int b;
    cin >> s >> b;

    a.resize(s.length());
    for (int i = 0; i < s.length(); i++)
        a[i] = (int) s[i] - '0';

    auto key = decrypt(b, 1);
    for (int i : key)
        cout << i << " ";
    cout << endl;

    return 0;
}