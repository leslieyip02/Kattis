n = int(input())

r = []
for _ in range(n):
    k = int(input())
    rn = input()

    ps = False
    pc = False
    for _ in range(k):
        mi = input().strip()
        if mi == "pea soup":
            ps = True
        if mi == "pancakes":
            pc = True

    if ps and pc:
        r.append(rn)

if len(r) > 0:
    print(r[0])
else:
    print("Anywhere is fine I guess")