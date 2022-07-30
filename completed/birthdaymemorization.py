bdays = {}

for _ in range(int(input())):
    s, c, d = input().split(" ")
    bdays[d] = bdays.get(d, (s, int(c)))
    if int(c) > bdays[d][1]:
        bdays[d] = (s, int(c))

print(len(bdays.keys()))
for n in sorted(bdays.values()):
    print(n[0])