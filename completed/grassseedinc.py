c, l = float(input()), int(input())

sum = 0
for _ in range(l):
    w, h = [float(i) for i in input().strip().split(" ")]
    sum = sum + w * h * c

print(sum)

