MAX = 30
dp = [[0 for _ in range(8)] for _ in range(MAX + 1)]
dp[0][7] = 1

for i in range(1, MAX + 1):
    dp[i][0] = dp[i - 1][7]
    dp[i][1] += dp[i - 1][6]
    dp[i][3] += dp[i - 1][4]
    dp[i][3] += dp[i - 1][7]
    dp[i][4] += dp[i - 1][3]
    dp[i][6] += dp[i - 1][7]
    dp[i][6] += dp[i - 1][1]
    dp[i][7] += dp[i - 1][3]
    dp[i][7] += dp[i - 1][6]
    dp[i][7] += dp[i - 1][0]

n = int(input())
while n != -1:
    print(dp[n][7])
    n = int(input())
