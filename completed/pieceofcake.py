n, h, v = [int(i) for i in input().strip().split(" ")]
h = max(h, n - h)
v = max(v, n - v)
print(h * v * 4)