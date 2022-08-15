a, b = input().split(" ")
grid = [["." for _ in range(len(a))] for _ in range(len(b))]

for i in range(len(a)):
    try:
        bi = b.index(a[i])
        ai = i
        break
    except:
        continue

grid[bi] = [i for i in a]
for i in range(len(b)):
    grid[i][ai] = b[i]

for row in grid:
    print("".join(row))