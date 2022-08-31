t = 1
n = int(input())
while n != 0:
    zoo = {}
    for _ in range(n):
        ln = input().split(" ")
        a = ln[-1].lower()
        zoo[a] = zoo.get(a, 0) + 1

    print(f"List {t}:")
    for a in sorted(zoo.keys()):
        print(f"{a} | {zoo[a]}")

    t += 1
    n = int(input())