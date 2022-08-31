n = input()
m = input()

l = max(len(n), len(m))
n = [int(i) for i in n.zfill(l)]
m = [int(i) for i in m.zfill(l)]

for i in range(l - 1, -1, -1):
    if n[i] < m[i]:
        n.pop(i)
    elif m[i] < n[i]:
        m.pop(i)

n = "".join([str(i) for i in n])
m = "".join([str(i) for i in m])

print("YODA" if len(n) == 0 else int(n))
print("YODA" if len(m) == 0 else int(m))