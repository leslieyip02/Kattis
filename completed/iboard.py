import sys

for line in sys.stdin:
    line = line.strip()

    l = r = 0
    for c in line:
        v = ord(c)
        for _ in range(7):
            if v & 1:
                l ^= 1
            else:
                r ^= 1

            v >>= 1

    print("trapped" if l + r else "free")
