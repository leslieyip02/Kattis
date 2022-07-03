n, k = [int(i) for i in input().strip().split(" ")]

score = 0
for _ in range(k):
    score = score + int(input())

min = (score + (n - k) * -3) / n
max = (score + (n - k) * 3) / n
print(f"{min} {max}")