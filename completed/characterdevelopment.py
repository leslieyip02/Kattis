from math import comb

n = int(input())

dp = [0 for _ in range(31)]
for i in range(2, n + 1):
    for j in range(2, i + 1):
        dp[i] += comb(i, j)

print(dp[n])