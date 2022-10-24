#include <iostream>
#include <set>
#include <cstring>
using namespace std;

const int MAX = 10001;

int happy[MAX];
bool primes[MAX];

void sieve()
{
    primes[0] = primes[1] = false;
 
    for (int i = 2; i * i <= MAX; i++)
        if (primes[i] == true)
            for (int j = i * i; j <= MAX; j += i)
                primes[j] = false;
}

bool is_prime(int n)
{
    return primes[n];
}

bool is_happy(int n)
{
    set<int> visited;

    while (happy[n] == 0 && visited.find(n) == visited.end())
    {
        visited.insert(n);

        int s = 0;
        while (n > 0)
        {
            int d = n % 10;
            s += d * d;
            n /= 10;
        }
        
        n = s;
    }

    if (visited.find(n) != visited.end())
        happy[n] = -1;

    for (int i : visited)
        happy[i] = happy[n];

    return happy[n] == 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(primes, true, sizeof(primes));
    sieve();

    memset(happy, 0, sizeof(happy));
    happy[1] = true;

    int p, k, m;
    cin >> p;

    while (p--)
    {
        cin >> k >> m;

        bool is_happy_prime = is_prime(m) && is_happy(m);
        cout << k << ' ' << m << ' ' << (is_happy_prime ? "YES" : "NO") << '\n';
    }

    return 0;
}