from math import ceil, log2

k = int(input())
s = ceil(log2(k))
d = 1 << s

while not (k & 1):
    s -= 1
    k >>= 1

print(d, s)