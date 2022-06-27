from math import sqrt

for _ in range(int(input())):
    encrypted = input()
    w = int(sqrt(len(encrypted)))

    grid = []
    for i in range(w):
        grid.append(encrypted[i * w : (i + 1) * w])

    for i in range(w):
        for line in grid:
            print(line[w - i - 1], end="")
    print()