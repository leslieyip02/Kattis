s, t, n = [int(i) for i in input().strip().split(" ")]
d = [int(i) for i in input().strip().split(" ")]
b = [int(i) for i in input().strip().split(" ")]
c = [int(i) for i in input().strip().split(" ")]

x = 0
for i in range(n):
    x = x + d[i]
    x = x + x % c[i]
    x = x + b[i]
x = x + d[n]

print("yes" if x < t - s else "no")