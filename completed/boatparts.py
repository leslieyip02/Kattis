parts = set()
p, n = [int(i) for i in input().split(" ")]
for i in range(1, n + 1):
    parts.add(input())
    if len(parts) == p:
        print(i)
        quit()

print("paradox avoided")