tb = 0
lr = 0

n = int(input())
for _ in range(n):
    sw = input()

    if sw[0] == '0':
        tb += 1
    if sw[1] == '0':
        tb += 1
    if sw[2] == '0':
        lr += 1
    if sw[3] == '0':
        lr += 1

c = 0
while tb >= 2 and lr >= 2:
    c += 1
    tb -= 2
    lr -= 2
print(c, tb, lr)