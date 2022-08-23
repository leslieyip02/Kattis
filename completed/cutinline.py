line = []

n = int(input())
for _ in range(n):
    line.append(input())

c = int(input())
for _ in range(c):
    ch = input().split(" ")

    if ch[0] == "cut":
        line.insert(line.index(ch[2]), ch[1])
    else:
        line.pop(line.index(ch[1]))

for l in line:
    print(l)