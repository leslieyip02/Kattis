o = [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)]
g = []

def mark(x0, y0):
    g[y0][x0] = "."
    for d in o:
        x1 = x0 + d[0]
        y1 = y0 + d[1]
        if 0 <= x1 < n and 0 <= y1 < m:
            if g[y1][x1] == "#":
                mark(x1, y1)

m, n = [int(i) for i in input().split(" ")]
for _ in range(m):
    g.append([i for i in input()])

c = 0
for y in range(m):
    for x in range(n):
        if g[y][x] == "#":
            c+= 1
            mark(x, y)
print(c)
