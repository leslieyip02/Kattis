#include <iostream>
using namespace std;

#define ull unsigned long long

int main()
{
    ull N, A, S, t;
    string p;   
    cin >> N >> p;
    bool x = p == "antal";

    ull max_a = 0;
    ull max_s = 0;
    ull max_t = 0;
    ull max_i = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> A >> S;
        t = A + S;
        if (t > max_t || (t == max_t &&
            ((x && A > max_a) || (!x && S > max_s))))
        {
            max_a = A;
            max_s = S;
            max_t = t;
            max_i = i;
        }
    }
    cout << max_i << '\n';
    return 0;
}