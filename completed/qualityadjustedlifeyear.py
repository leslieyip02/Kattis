n = int(input())

x = 0
for _ in range(n):
    q, y = [float(i) for i in input().strip().split(" ")]
    x = x + q * y

print(x)