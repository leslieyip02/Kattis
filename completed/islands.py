m = []
o = [(1, 0), (-1, 0), (0, 1), (0, -1)]
def trace(x0, y0):
    m[y0][x0] = 'W'
    for d in o:
        x1 = x0 + d[0]
        y1 = y0 + d[1]
        if 0 <= x1 < c and 0 <= y1 < r:
            if m[y1][x1] == 'L' or m[y1][x1] == 'C':
                trace(x1, y1)

r, c = [int(i) for i in input().split(" ")]
for _ in range(r):
    m.append([i for i in input()])

i = 0
for y in range(r):
    for x in range(c):
        if m[y][x] == 'L':
            i += 1
            trace(x, y)

print(i)