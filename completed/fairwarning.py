def gcd(a, b):
    if b == 0:
        return a;
    return gcd(b, a % b);

C = int(input())
for x in range(1, C + 1):
    n = [int(i) for i in input().split()][1:]
    d = [abs(n[i] - n[i - 1]) for i in range(1, len(n))]

    T = d[0]
    for i in d:
        T = gcd(i, T)

    m = min(n)
    p = m % T
    y = T - p if p != 0 else 0
    print(f"Case #{x}: {y}")
