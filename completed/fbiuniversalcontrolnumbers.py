dts = [
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'C', 'D', 'E', 'F', 'H', 'J', 'K', 'L', 'M',
    'N', 'P', 'R', 'T', 'V', 'W', 'X'
]

pc = {
    'B': '8', 'G': 'C', 'I': '1', 'O': '0', 'Q': '0',
    'S': '5', 'U': 'V', 'Y': 'V', 'Z': '2'
}

f = [ 2, 4, 5, 7, 8, 10, 11, 13 ]

def check(ln):
    c = ln[-1]

    s = 0
    for i, j in zip(ln[:-1], f):
        s += (dts.index(i) * j) % 27
    s %= 27

    return c == dts[s]

p = int(input())
for _ in range(p):
    k, ln = [i for i in input().split(" ")]
    print(k, end=" ")

    for o, n in pc.items():
        ln = ln.replace(o, n)

    if not check(ln):
        print("Invalid")
    else:
        c = 0
        for i in range(8):
            c += 27 ** (7 - i) * dts.index(ln[i])
        print(c)
