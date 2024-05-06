import sys


def factorial(n):
    f = 1
    for i in range(2, n + 1):
        f *= i
    return f

for line in sys.stdin:
    n = factorial(len(line.strip()))
    d = {}
    for c in line:
        d[c] = d.get(c, 0) + 1
    for v in d.values():
        n //= factorial(v)
    print(int(n))