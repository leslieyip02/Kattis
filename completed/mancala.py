p = int(input())
for _ in range(p):
    k, n = [int(i) for i in input().split(" ")]

    bins = [0 for _ in range(81)]
    bins[0] = n
    while bins[0] > 0:
        c = 0
        i = 0
        while bins[i] != 0:
            bins[i] -= 1
            c += 1
            i += 1


        bins[i] += c

    for i in range(80, -1, -1):
        if bins[i] != 0:
            bins = bins[1:i + 1]
            break

    bins = [str(i) for i in bins]
    b = len(bins)
    x = b // 10

    print(k, b)
    for i in range(x):
        print(" ".join(bins[i * 10:(i + 1) * 10]))
    print(" ".join(bins[x * 10:]))
