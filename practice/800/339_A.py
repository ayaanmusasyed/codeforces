nums = list(map(int, input().split("+")))
nums.sort()
res = []
for i in range(len(nums) - 1): 
    res.append(str(nums[i]))
    res.append("+")
res.append(nums[-1])
print(*res, sep='', end='')