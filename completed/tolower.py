def lower_first(s: str) -> str:
    s = s[0].lower() + s[1:]
    return s

p, t = [int(i) for i in input().split(' ')]

c = 0
for i in range(p):
    if all([lower_first(input()).islower() for _ in range(t)]):
        c += 1

print(c)