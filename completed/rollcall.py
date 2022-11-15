import sys

p = {}
q = []
for line in sys.stdin:
    f, l = line.strip().split(' ')
    p[f] = p.get(f, [])
    p[f].append(l)
    q.append((f, l))

q = sorted(q, key=lambda n: (n[1], n[0]))

for name in q:
    f, l = name
    print(f, l if len(p[f]) > 1 else "")
