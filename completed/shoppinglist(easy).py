items = {}

n, m = [int(i) for i in input().split(" ")]
for _ in range(n):
    for i in input().split(" "):
        items[i] = items.get(i, 0) + 1

common = []
for i, c in items.items():
    if c == n:
        common.append(i)

print(len(common))
for i in sorted(common):
    print(i)