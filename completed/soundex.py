import sys

d = {
    'B': 1, 'F': 1, 'P': 1, 'V': 1,
    'C': 2, 'G': 2, 'J': 2, 'K': 2, 'Q': 2, 'S': 2, 'X': 2, 'Z': 2,
    'D': 3, 'T': 3,
    'L': 4,
    'M': 5, 'N': 5,
    'R': 6
}

for line in sys.stdin:
    p = ""
    for c in line.strip():
        v = d.get(c)
        if v and v != p:
            print(d.get(c), end="")

        p = v

    print()