x = []
y = []

for _ in range(3):
    a, b = [int(i) for i in input().strip().split(" ")]
    x.append(a)
    y.append(b)

if x[0] == x[1]:
    print(x[2], end=" ")
elif x[0] == x[2]:
    print(x[1], end=" ")
else:
    print(x[0], end=" ")

if y[0] == y[1]:
    print(y[2])
elif y[0] == y[2]:
    print(y[1])
else:
    print(y[0])