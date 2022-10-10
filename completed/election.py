n = int(input())

c = {}
p = {}

for _ in range(n):
    name = input()
    party = input()

    c[name] = 0
    p[name] = party

m = int(input())
for _ in range(m):
    name = input()
    if name in c:
        c[name] += 1

v = 0
w = ""
tied = False
for name, votes in c.items():
    if votes == v:
        tied = True
        w = "tie"

    if votes > v:
        v = votes
        w = p[name]
        tied = False

print(w)