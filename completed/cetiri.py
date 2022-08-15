n = sorted([int(i) for i in input().split(" ")])

d1 = n[1] - n[0]
d2 = n[2] - n[1]

if d1 == d2:
    print(n[2] + d2)
elif d1 > d2:
    print(n[0] + d2)
else:
    print(n[1] + d1)