#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long
#define ull unsigned long long
#define MAX_N 100000000000 // 10^11
#define CACHE_SIZE 500

// Sieve of Eratosthenes to generate prime numbers from 1 to sqrt(N)
// https://www.geeksforgeeks.org/sieve-eratosthenes-0n-time-complexity/
static vector<bool> isPrime;
static vector<ull> primes;
static vector<ull> spf;
static vector<ull> pi { 0, 0 };
static ull t = 0;
void sieve(ull n)
{
    isPrime[0] = false;
    isPrime[1] = false;

    for (auto i = 2; i < n; i++)
    {
        if (isPrime[i])
        {
            t++;
            primes.push_back(i);
            spf[i] = i;
        }

        for (auto j = 0; j < primes.size() && i * primes[j] < n 
            && primes[j] <= spf[i]; j++)
        {
            isPrime[i * primes[j]] = false;
            spf[i * primes[j]] = primes[j];
        }
        
        pi.push_back(t);
    }
}

// Meissel-Lehmer Algorithm
// https://codegolf.stackexchange.com/questions/74269/calculate-the-number-of-primes-up-to-n
vector<ull> phiCache;
ull phi(ull x, ull a)
{
    if (!a)
        return x;
    if (!x)
        return 0;
    if (x >= CACHE_SIZE)
        return phi(x, a - 1) - phi(x / primes[a - 1], a - 1);
    
    ull t = x + a * CACHE_SIZE;
    if (!phiCache[t])
        phiCache[t] = phi(x, a - 1) - phi(x / primes[a - 1], a - 1);
    return phiCache[t];
}

int main()
{
    int N;
    cin >> N;

    int smallPi[] = { 0, 0, 1, 2, 2, 3 };
    if (N < 6)
    {
        cout << smallPi[N] << endl;
        return 0;
    }

    ull rt2N = sqrt(N);
    ull rt3N = cbrt(N);
    ull upper = N / rt3N + 1;

    isPrime = vector<bool>(upper, true);
    spf = vector<ull>(upper);
    sieve(upper);

    isPrime.clear();
    spf.clear();

    ull a1 = pi[rt3N + 1];
    ull a2 = pi[rt2N + 1];

    phiCache = vector<ull>((a1 * CACHE_SIZE), 0);
    ull p = phi(N, a1);

    ll q = 0;
    for (auto i = a1; i < a2; i++)
        q += pi[N / primes[i]] - pi[primes[i]] + 1;

    cout << p + a1 - 1 - q << endl;

    return 0;
}

// works until 10^9
// doesn't work for 10^10 and 10^11