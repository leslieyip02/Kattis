n = int(input())
r = [[] for _ in range(n)]
for _ in range(3):
    for i, d in enumerate(input().split(' ')):
        r[i].append(int(d))
print(' '.join([str(sorted(c)[1]) for c in r]))