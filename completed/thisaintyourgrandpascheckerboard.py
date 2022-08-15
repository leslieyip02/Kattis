n = int(input())
grid = []
for i in range(n):
    row = [i for i in input()]
    if row.count("W") != row.count("B"):
        print(0)
        quit()

    for j in range(n - 2):
        if row[j] == row[j + 1] and row[j] == row[j + 2]:
            print(0)
            quit()
    
    grid.append(row)
    
for i in range(n):
    col = [grid[j][i] for j in range(n)]
    if col.count("W") != col.count("B"):
        print(0)
        quit()

    for j in range(n - 2):
        if col[j] == col[j + 1] and col[j] == col[j + 2]:
            print(0)
            quit()

print(1)
