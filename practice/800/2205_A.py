t = int(input())

for _ in range(t): 
    n = int(input())
    nums = list(map(int, input().split()))

    res = []
    m = 0
    i = -1 
    for j in range(n): 
        if nums[j] > m: 
            m = nums[j] 
            i = j

    temp = nums[0]
    nums[0] = m
    nums[i] = temp

    s = ""
    for i in nums: 
        s += str(i) + " "
    
    print(s)