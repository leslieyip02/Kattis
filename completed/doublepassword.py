n = 1
for d1, d2 in zip(input(), input()):
    if d1 != d2:
        n <<= 1
print(n)