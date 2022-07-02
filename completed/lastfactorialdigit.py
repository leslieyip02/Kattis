for _ in range(int(input())):
    n = int(input())

    digit = 1
    for i in range(1, n + 1):
        digit = digit * i
        if digit > 10:
            digit = digit % 10

    print(digit)