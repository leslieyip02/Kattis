t = int(input())
for _ in range(t):
    n, m = [int(i) for i in input().split(" ")]
    a = [0 for _ in range(m)]

    for _ in range(n):
        b = input()
        for i in range(m):
            if b[i] == '1':
                a[i] += 1

    for d in a:
        print(1 if d >= n / 2 else 0, end="")
    print()