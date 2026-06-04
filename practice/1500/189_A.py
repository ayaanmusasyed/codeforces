n, a, b, c = map(int, input().split())

sub = [a,b,c]
s = -1 
dp = [s] * (n + 1)
dp[0] = 0

for i in range(1, n + 1): 
    for t in sub: 
        if i >= t and dp[i - t] > -1: 
            dp[i] = max(dp[i], dp[i - t] + 1)

print(dp[n])