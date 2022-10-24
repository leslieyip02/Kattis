n = [int(i) for i in input().split(' ')]
k = int(input())

def choose(i, c):
    if c == 1:
        return n[i]

    s = 0
    for j in range(i + 1, 10):
        if n[j] > 0:
            s += choose(j, c - 1)

    return n[i] * s

t = 0
for i in range(10):
    t += choose(i, k)

print(t)