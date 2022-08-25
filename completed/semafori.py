n, l = [int(i) for i in input().split(" ")]

c = 0
t = 0
for _ in range(n):
    d, r, g = [int(i) for i in input().split(" ")]
    t += (d - c)
    c = d

    w = t % (r + g)
    if w <= r:
        t += r - w

t += l - d
print(t)