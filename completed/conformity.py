combis = {}

n = int(input())
for _ in range(n):
    student = tuple(sorted(input().split(" ")))
    combis[student] = combis.get(student, 0) + 1

c = [0, 0]
for p in combis.values():
    if p > c[0]:
        c[0] = p
        c[1] = p
    elif p == c[0]:
        c[1] += p

print(c[1])