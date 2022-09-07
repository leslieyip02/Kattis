d = [(1, 0), (-1, 0), (0, 1), (0, -1)]

r, c, n = [int(i) for i in input().split(" ")]
t = [[0 for _ in range(c)] for _ in range(r)]
for _ in range(n):
    y, x = [int(i) - 1 for i in input().split(" ")]
    t[y][x] = 2

z = 1
conquered = True
for y0 in range(r):
    for x0 in range(c):
        if t[y0][x0] == 0:
            conquered = False

while not conquered:
    z += 1
    conquered = True
    
    for y0 in range(r):
        for x0 in range(c):
            if 0 < t[y0][x0] <= z:
                for o in d:
                    x1 = x0 + o[0]
                    y1 = y0 + o[1]
                
                    if 0 <= x1 < c and 0 <= y1 < r and t[y1][x1] == 0:
                        t[y1][x1] = z + 1

    for y0 in range(r):
        for x0 in range(c):
            if t[y0][x0] == 0:
                conquered = False

print(z)