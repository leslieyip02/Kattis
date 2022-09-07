c, k = [int(i) for i in input().split(" ")]
for _ in range(k):
    c /= 10

c = round(c)
for _ in range(k):
    c *= 10

print(c)
