from math import pi, asin, cos

r, h, s = [int(i) for i in input().split()]
while not (r == 0 and h == 0 and s == 0):
    a = asin(r / h)
    b = pi / 2 - a
    c = 2 * (pi - b) * r
    d = 2 * h * cos(a)
    print(f"{round((c + d) * (1 + s / 100), 2):.2f}")

    r, h, s = [int(i) for i in input().split()]
