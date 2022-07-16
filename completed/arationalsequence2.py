from math import pow

for _ in range(int(input())):
    k, f = input().split(" ")
    p, q = [int(i) for i in f.split(("/"))]

    r = []
    while p / q != 1:
        if p / q < 1:
            q -= p
            r.insert(0, -1)
        else:
            p -= q
            r.insert(0, 1)

    n = 1
    total_nodes = 1
    for i in range(1, len(r) + 1):
        d = n - pow(2, i)
        n = pow(2, i + 1) + d * 2 + (0 if r[i - 1] < 0 else 1)

    print(k, int(n))