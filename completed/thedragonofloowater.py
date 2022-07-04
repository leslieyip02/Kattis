while True:
    n, m = [int(i) for i in input().split(" ")]

    if n == 0 and m == 0:
        quit()

    heads = []
    for _ in range(n):
        heads.append(int(input()))

    knights = []
    for _ in range(m):
        knights.append(int(input()))

    heads.sort()
    knights.sort()

    c = 0
    for knight in knights:
        if len(heads) == 0:
            break
        elif knight >= heads[0]:
            c += knight
            heads.pop(0)

    if len(heads) > 0:
        print("Loowater is doomed!")
    else:
        print(c)
