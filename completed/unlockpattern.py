from math import sqrt

d = 0
pad = [[int(i) for i in input().split(" ")] for _ in range(3)]

for n in range(1, 9):
    for y in range(3):
        if n in pad[y]:
            i1 = (pad[y].index(n), y)
        if n + 1 in pad[y]:
            i2 = (pad[y].index(n + 1), y)
    d += sqrt((i1[0] - i2[0]) ** 2 + (i1[1] - i2[1]) ** 2)

print(d)