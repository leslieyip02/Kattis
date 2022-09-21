p = []
for c in input():
    if c == '<':
        p.pop()
    else:
        p.append(c)

print(''.join(p))
