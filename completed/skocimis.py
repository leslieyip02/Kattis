k = [int(i) for i in input().split(" ")]

c = 0
while k[1] - k[0] > 1 or k[2] - k[1] > 1:
    if k[1] - k[0] > k[2] - k[1]:
        k.insert(1, k[1] - 1)
        k.pop(3)
    else:
        k.insert(2, k[2] - 1)
        k.pop(0)

    c += 1

print(c)