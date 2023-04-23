import sys

p = {}
b = {}
d = 1

for line in sys.stdin:
    line = line.strip()
    if line == "OPEN":
        p = {}
        b = {}
    elif line == "CLOSE":
        print(f"Day {d}")
        for name in sorted(b.keys()):
            print(f"{name} ${b[name]:.2f}")
        print()

        d += 1
    else:
        x, y, z = line.split(" ")

        if x == "ENTER":
            p[y] = int(z)
        else:
            b[y] = b.get(y, 0) + (int(z) - p[y]) * 0.1