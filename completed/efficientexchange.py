import sys
sys.setrecursionlimit(2000)

c = {}

def ex(n):
    if n not in c:
        a = n % 10;
        b = 10 - a;
        if n < 10:
            return min(a, b + 1)

        c[n] = min(a + ex(n // 10), b + ex(n // 10 + 1))
    return c[n]

print(ex(int(input())))