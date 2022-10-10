import sys

for ln in sys.stdin:
    n = int(ln)

    d = 1
    p = 1

    while p % n != 0:
        p = (p * 10 + 1) % n
        d += 1

    print(d)