n = int(input())

for _ in range(n):
    a, b = input(), input()
    
    print(a)
    print(b)

    for i, j in zip(a, b):
        if i == j:
            print(".", end="")
        else:
            print("*", end="")

    print("\n")