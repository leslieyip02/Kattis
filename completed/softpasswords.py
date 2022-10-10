s = [i for i in input()]
p = [i for i in input()]

if s == p:
    print("Yes")
    quit()

ok = False
if len(s) == len(p):
    for i in range(len(s)):
        if p[i].isupper():
            p[i] = p[i].lower()
        else:
            p[i] = p[i].upper()

    ok = s == p
else:
    for i in range(10):
        if p + [str(i)] == s or [str(i)] + p == s:
            ok = True
            break

print("Yes" if ok else "No")