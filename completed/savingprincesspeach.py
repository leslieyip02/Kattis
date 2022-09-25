n, y = [int(i) for i in input().split(' ')]
found = set([int(input()) for _ in range(y)])

for i in range(n):
    if i not in found:
        print(i)

print(f"Mario got {len(found)} of the dangerous obstacles.")