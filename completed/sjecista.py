n = int(input())
i = 0

for x in range(2, n - 1):
    i += (x - 1) * (n - 1 - x)

i *= n
i //= 4

print(i)
