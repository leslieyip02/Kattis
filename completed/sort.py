n, c = [int(i) for i in input().split(' ')]

f = {}
o = []
for x in [int(i) for i in input().split(' ')]:
    if x not in f:
        f[x] = 0
        o.append(x)

    f[x] += 1

for x in sorted(o, key=f.get, reverse=True):
    print(f"{x} " * f[x], end="")