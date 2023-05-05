import sys

p = {}
q = 0
for line in sys.stdin:
    line = line.strip()
    p[line] = p.get(line, 0) + 1
    q += 1

for key in sorted(p.keys()):
    print(f"{key} {p[key] / q * 100}")