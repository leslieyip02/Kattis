k = int(input())
x = [1 if i == 'T' else 0 for i in input()]
y = [1 if i == 'T' else 0 for i in input()]

d = 0
for i in range(len(x)):
    a = x[i] ^ y[i]
    if a == 1:
        d += 1

s = len(x) - d
if s > k:
    print(k + d)
else:
    print(s + d - (k - s))
