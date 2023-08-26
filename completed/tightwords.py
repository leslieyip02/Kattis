import sys

def choose(c, k, n):
    if m.get((c, n)):
        return m[(c, n)]
    if n == 0:
        p = 1
    elif n == 1:
        p = 1 / (k + 1);
        if c != 0:
            p += 1 / (k + 1)
        if c != k:
            p += 1 / (k + 1)
    else:
        p = 1 / (k + 1) * choose(c, k, n - 1)
        if c != 0:
            p += 1 / (k + 1) * choose(c - 1, k, n - 1)
        if c != k:
            p += 1 / (k + 1) * choose(c + 1, k, n - 1)
    m[(c, n)] = p
    return p

for line in sys.stdin:
    m = {}
    k, n = [int(i) for i in line.split()]
    p = 0
    for i in range(k + 1):
        p += 1 / (k + 1) * choose(i, k, n - 1)
    print(p * 100)