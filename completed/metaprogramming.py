import sys

v = {}
for ln in sys.stdin:
    c = ln.split(" ")
    if c[0] == "define":
        _, i, x = c
        v[x.strip()] = int(i)
    else:
        _, x, y, z = c

        x = x.strip()
        z = z.strip()

        if x not in v or z not in v:
            print("undefined")
        elif y == '<':
            print("true" if v[x] < v[z] else "false")
        elif y == '>':
            print("true" if v[x] > v[z] else "false")
        else:
            print("true" if v[x] == v[z] else "false")
