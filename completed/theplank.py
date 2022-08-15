planks = [
    [[1]],
    [[1, 1], [2]],
    [[1, 1, 1], [2, 1], [1, 2], [3]]
]

n = int(input())
for i in range(4, n + 1):
    pi = []

    for c1 in planks[i - 2]:
        if sum(c1) + 1 == i:
            c = c1.copy()
            c.append(1)
            pi.append(c)

    for c2 in planks[i - 3]:
        if sum(c2) + 2 == i:
            c = c2.copy()
            c.append(2)
            pi.append(c)

    for c3 in planks[i - 4]:
        if sum(c3) + 3 == i:
            c = c3.copy()
            c.append(3)
            pi.append(c)

    planks.append(pi)

print(len(planks[-1]))