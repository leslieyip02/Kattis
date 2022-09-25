import sys

for ln in sys.stdin:
    f = {}

    s = [i for i in ln.strip()]
    for l in s:
        f[l] = f.get(l, 0) + 1

    e = 0
    while len(f) > 2:
        n = ""
        m = 1000
        for l, c in f.items():
            if c < m:
                m = c
                n = l

        e += m
        del f[n]

    print(e)