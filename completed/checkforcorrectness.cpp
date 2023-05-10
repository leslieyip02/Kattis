#include <cstdio>
using namespace std;

const int M = 10000;

int add(unsigned long a, unsigned long b)
{
    unsigned long c = a + b;
    return c % M;
}

int multiply(unsigned long a, unsigned long b)
{
    unsigned long c = (a % M) * (b % M);
    return c % M;
}

int power(unsigned long a, unsigned long b)
{
    int m[32];
    m[0] = a % M;
    for (int i = 1; i < 32; i++)
    {
        m[i] = (m[i - 1] * m[i - 1]) % M;
    }

    int c = 0;
    unsigned long d = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            d = (d * m[c]) % M;
        }

        b >>= 1;
        c++;
    }

    return d;
}

int main()
{
    unsigned long a, b, c;
    char op;

    while (scanf("%lu %c %lu", &a, &op, &b) != EOF)
    {
        c = op == '+' ? add(a, b) : op == '*' ? multiply(a, b)
                                              : power(a, b);
        printf("%lu\n", c);
    }

    return 0;
}