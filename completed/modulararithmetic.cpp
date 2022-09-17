#include <iostream>
#include <cmath>
using namespace std;

#define ll long long

ll add(ll x, ll y, ll n)
{
    return (x % n + y % n) % n;
}

ll subtract(ll x, ll y, ll n)
{
    return (x % n - y % n + n) % n;
}

ll multiply(ll x, ll y, ll n)
{
    return ((x % n) * (y % n)) % n;
}

// ax + by = gcd(a, b)
ll euclidean_algorithm(ll a, ll b, ll *x, ll *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    
    ll x1, y1;
    ll gcd = euclidean_algorithm(b % a, a, &x1, &y1);
    
    *x = y1 - (b / a) * x1;
    *y = x1;
    
    return gcd;
}

ll mod_inverse(ll b, ll n)
{
    ll x, y;
    ll gcd = euclidean_algorithm(b, n, &x, &y);
    
    return (gcd == 1) ? (x % n + n) % n : -1;
}

ll divide(ll x, ll y, ll n)
{
    ll inv = mod_inverse(y, n);
    if (inv == -1)
        return -1;
    
    return inv == -1 ? -1 : ((x % n) * inv) % n;
}

int main()
{
    ll n, x, y;
    int t;
    char op;
    cin >> n >> t;
    while (n != 0 || t != 0)
    {
        while (t--)
        {
            cin >> x >> op >> y;
            switch (op)
            {
                case '+':
                    cout << add(x, y, n) << '\n';
                    break;
                case '-':
                    cout << subtract(x, y, n) << '\n';
                    break;
                case '*':
                    cout << multiply(x, y, n) << '\n';
                    break;
                default:
                    cout << divide(x, y, n) << '\n';
                    break;
            }
        }
        cin >> n >> t;
    }

    return 0;
}