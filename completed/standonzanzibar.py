for _ in range(int(input())):
    log = [int(i) for i in input().split(" ")]

    n, i = 0, 1
    while log[i] != 0:
        n = n + max(log[i] - log[i - 1] * 2, 0)
        i = i + 1

    print(n)