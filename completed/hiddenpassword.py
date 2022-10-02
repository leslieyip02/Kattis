p, msg = [[j for j in i] for i in input().split(' ')]
msg = [i for i in msg if i in p]

ok = True
while len(p) > 0:
    t = p.pop(0)
    if len(msg) == 0 or msg.pop(0) != t:
        ok = False
        break

    msg = [i for i in msg if i in p]

print("PASS" if ok else "FAIL")