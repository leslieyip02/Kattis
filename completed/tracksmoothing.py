from math import pow, sqrt, pi

for _ in range(int(input())):
    r, n = [int(i) for i in input().split(" ")]

    pts = []
    for _ in range(n):
        pts.append([int(i) for i in input().split(" ")])
    pts.append(pts[0])

    length = 0
    for i in range(n):
        length += sqrt(pow(pts[i][0] - pts[i + 1][0], 2) + pow(pts[i][1] - pts[i + 1][1], 2))

    perimeter = length - 2 * pi * r
    scale = perimeter / length

    if scale < 0:
        print("Not possible")
    else:
        print(scale)