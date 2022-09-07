from math import pow

n = int(input())
for _ in range(n):
    t = input().split(",")

    d = 0
    for i in range(len(t)):
        if len(t[i]) == 0:
            continue
        d += int(t[i]) * pow(60, len(t) - i - 1)

    print(int(d))