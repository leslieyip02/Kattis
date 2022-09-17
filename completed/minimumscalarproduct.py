t = int(input())
for i in range(1, t + 1):
    n = int(input())
    a = sorted([int(i) for i in input().split(" ")])
    b = sorted([int(i) for i in input().split(" ")], reverse=True)

    print(f"Case #{i}: {sum([i * j for i, j in zip(a, b)])}")
