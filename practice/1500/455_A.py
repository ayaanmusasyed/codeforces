n = int(input())
nums = list(map(int, input().split()))

f = {}
m = 0
for i in range(n): 
    if nums[i] > m: 
        m = nums[i]
    if nums[i] in f: 
        f[nums[i]] += 1
    else: 
        f[nums[i]] = 1

arr = [i for i in range(1, m + 1)]
for x in arr: 
    if x not in f: 
        f[x] = 0

# Cannot take consequtive 
# Let dp[i] be the best possible score up to index i 
dp = [0] * len(arr)
dp[0] = f[arr[0]] * arr[0]

for i in range(1, len(arr)): 
    dp[i] = max(dp[i - 1], dp[i - 2] + (f[arr[i]] * arr[i]))

print(dp[-1])