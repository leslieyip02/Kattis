n = int(input())
s = {}
for _ in range(n):
    i, j, k = input().split()
    s[i] = s.get(i, {})
    s[i][j] = int(k)

ok = False
for v in s.values():
    if v.get("any", 0) > 1 or ("left" in v and "right" in v):
        ok = True
        break

if not ok:
    print("impossible")
else:
    m = 1
    for v in s.values():
        a = v.get("any", 0)
        l = v.get("left", 0)
        r = v.get("right", 0)

        if not a and l | r:
            m += max(l, r)
        elif a:
            m += max((l, r, 1))
    print(m)