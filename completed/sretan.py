from math import floor, log2

k = int(input())
d = floor(log2(k + 1))

k -= 1
for i in range(1, d):
    k -= 1 << i

n = []
for _ in range(d):
    n.append('7' if k & 1 else '4')
    k >>= 1

print(''.join(reversed(n)))
