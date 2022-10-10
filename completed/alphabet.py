s = [i for i in input()]
t = [0 for _ in s]
t[-1] = 1

def jump(i):
    if s[i] == 'z':
        t[i] = 1

    if t[i] != 0:
        return t[i]

    c = 0
    for j in range(i + 1, len(s)):
        if s[j] > s[i]:
            c = max(jump(j), c)

    t[i] = c + 1
    return t[i]

m = 0
for i in range(len(s) - 1, -1, -1):
    m = max(jump(i), m)

print(26 - m)