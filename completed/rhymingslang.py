d = set()
S = input()
E = int(input())
for _ in range(E):
    w = input().split()
    ok = False
    for i in w:
        if S.endswith(i):
            ok = True
            break
    if ok:
        d.update(w)
P = int(input())
for _ in range(P):
    l = input()
    ok = False
    for i in d:
        if l.endswith(i):
            ok = True
            break
    print("YES" if ok else "NO")
