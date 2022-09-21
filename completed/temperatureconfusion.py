a, b = [int(i) for i in input().split('/')]
a = (a - b * 32) * 5
b = b * 9

for i in range(min(abs(a), abs(b)), 1, -1):
    if a % i == 0 and b % i == 0:
        a /= i
        b /= i

print(f"{int(a)}/{1 if a == 0 else int(b)}")