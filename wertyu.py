import sys

keys = ["1234567890-=", "QWERTYUIOP[]\\", "ASDFGHJKL;'", "ZXCVBNM,./"]

for ln in sys.stdin:
    for t in ln:
        for r in keys:
            if t in r:
                t = r[r.find(t) - 1]
                break

        print(t, end="")