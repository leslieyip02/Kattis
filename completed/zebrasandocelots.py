n = int(input())

i = 1
t = 0
for _ in range(n):
    if input() == 'O':
        t += 1 << (n - i)
    i += 1

print(t)