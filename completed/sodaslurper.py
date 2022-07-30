e, f, c = [int(i) for i in input().split(" ")]
e += f
count = 0
while e >= c:
    e -= (c - 1)
    count += 1
print(count)