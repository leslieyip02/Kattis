# https://open.kattis.com/problems/inflation2

N = int(input())
v = {}
P = 0
for p in input().split():
    p = int(p)
    P += p
    v[p] = v.get(p, 0) + 1

z = 0
Q = int(input())
for _ in range(Q):
    l = input().split()
    if l[0] == "INFLATION":
        x = int(l[1])
        z += x
        P += x * N
    else:
        x, y = int(l[1]) - z, int(l[2]) - z
        if x != y and x in v.keys():
            P += (y - x) * v[x]
            v[y] = v.get(y, 0) + v[x]
            del v[x]
    print(P)