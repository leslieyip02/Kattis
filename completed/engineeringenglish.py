import sys

d = []
for ln in sys.stdin:
    for w in ln.strip().split(' '):
        if w.lower() in d:
            print('.', end=" ")
        else:
            print(w, end=" ")
            d.append(w.lower())

    print()