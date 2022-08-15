n, m = [int(i) for i in input().split(" ")]

f = [0 for _ in range(n)]
for _ in range(m):
    a, b = [int(i) for i in input().split(" ")]
    f[a - 1] += 1
    f[b - 1] += 1

for i in range(n):
    print(f[i] - (i + 1), end=" ")
print()