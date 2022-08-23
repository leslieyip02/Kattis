n = int(input())
a = [0 for _ in range(n)]
m = [[int(i) for i in input().split(" ")] for _ in range(n)]

for i in range(n):
    for j in range(n):
        a[i] |= m[i][j]

print(" ".join([str(i) for i in a]))
