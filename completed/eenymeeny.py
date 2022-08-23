k = len(input().split(" ")) - 1
n = int(input())

kids = [input() for _ in range(n)]
a = []
b = []

i = 0
while len(kids) > 0:
    i = (i + k) % len(kids)

    if len(a) == len(b):
        a.append(kids[i])
    else:
        b.append(kids[i])

    kids.pop(i)

print(len(a))
for ai in a:
    print(ai)

print(len(b))
for bi in b:
    print(bi)
