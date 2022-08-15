from math import pow

for _ in range(int(input())):
    k, n = [int (i) for i in input().split(" ")]

    shifts = []
    while n > 1:
        shifts.append(-1 if n % 2 == 0 else 1)
        n //= 2

    p = q = 1
    for shift in shifts[::-1]:
        if shift == -1:
            q = p + q
        else:
            p = p + q

    print(f"{k} {p}/{q}")