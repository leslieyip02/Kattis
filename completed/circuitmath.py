n = int(input())
v = [i == 'T' for i in input().split(" ")]

c = input().split(" ")
for i in range(len(c)):
    if c[i].isalpha():
        c[i] = v[ord(c[i]) - 65]

while len(c) > 1:
    for i in range(len(c)):
        if c[i] == '*':
            c[i - 2] &= c[i - 1]
            c.pop(i)
            c.pop(i - 1)
            break
        elif c[i] == '+':
            c[i - 2] |= c[i - 1]
            c.pop(i)
            c.pop(i - 1)
            break
        elif c[i] == '-':
            c[i - 1] = not c[i - 1]
            c.pop(i)
            break

print('T' if c[0] else 'F')