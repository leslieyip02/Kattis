t = int(input())
for _ in range(t):
    n = int(input())

    c = [str(n)]
    for i in range(n - 1, 0, -1):
        c.insert(0, str(i))

        for _ in range(i):
            c.insert(0, c[-1])
            c.pop(-1)

    print(" ".join(c))