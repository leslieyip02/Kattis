n = int(input())
d = {}

for _ in range(n):
    a, b, c = input().split()
    d[b] = c

m = 0
for x in d.keys():
    l = 1
    w = d[x]
    while w := d.get(w):
        l += 1
        if w == x:
            break
    if w:
        m = max(l, m)
print(m if m else "No trades possible")
