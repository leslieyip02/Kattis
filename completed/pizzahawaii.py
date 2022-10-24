t = int(input())
for _ in range(t):
    n = int(input())

    foreign = {}
    native = {}
    ingreidents = {}

    for _ in range(n):
        x = input()
        y = input().split(' ')[1:]
        z = input().split(' ')[1:]

        for i in y:
            foreign[i] = foreign.get(i, set())
            foreign[i].add(x)

            ingreidents[i] = ingreidents.get(i, set())
            ingreidents[i].update(z)
        
        for i in z:
            native[i] = native.get(i, set())
            native[i].add(x)

    for i in sorted(ingreidents):
        for j in sorted(ingreidents[i]):
            if foreign[i] == native[j]:
                print(f"({i}, {j})")

    print()
