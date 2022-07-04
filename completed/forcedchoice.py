n, p, s = [int(i) for i in input().split(" ")]

cards = list(range(1, n + 1))
for i in range(s):
    chosen = [int(i) for i in input().split(" ")][1:]
    print("KEEP" if p in chosen else "REMOVE")