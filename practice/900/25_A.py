n = int(input())
nums = list(map(int, input().split()))
o = 0
e = 0
for i in range(n): 
    nums[i] = nums[i] % 2
    if nums[i] == 1: 
        o += 1
    else: 
        e += 1

if o > e: 
    for i in range(n): 
        if nums[i] == 0: 
            print(i + 1)
else: 
    for i in range(n): 
        if nums[i] == 1: 
            print(i + 1)