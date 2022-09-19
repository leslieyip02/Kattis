b, k, g = [int(i) for i in input().split(' ')]

b -= 1
k //= g

print(b // k + (0 if b % k == 0 else 1))