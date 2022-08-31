p = [input() for _ in range(4)]

c = 0
for i in range(4):
    for j in range(4):
        if p[i][j] == '.':
            continue

        k = ord(p[i][j]) - 65
        c += abs(i - k // 4) + abs(j - k % 4)

print(c)
