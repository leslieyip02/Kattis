n, m = [int(i) for i in input().strip().split(" ")]

sums = {}

for i in range(1, n + 1):
    for j in range(1, m + 1):
        sum = i + j
        sums[sum] = sums.get(sum, 0) + 1

max = 0
outcomes = []
for k, sum in sums.items():
    if sum > max:
        outcomes = [k]
        max = sum
    elif sum == max:
        outcomes.append(k)

for outcome in outcomes:
    print(outcome)