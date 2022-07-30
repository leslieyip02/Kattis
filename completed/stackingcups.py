cups = {}
for _ in range(int(input())):
    a, b = input().split(" ")
    try:
        b = int(b)
        cups[a] = b
    except:
        cups[b] = int(a) / 2

order = sorted(cups, key=cups.get)
for o in order:
    print(o)