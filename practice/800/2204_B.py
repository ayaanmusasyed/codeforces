t = int(input())

for _ in range(t): 
    n = int(input())
    nums = list(input().split())
    for i in range(n): 
        nums[i] = int(nums[i])

    ans = 0
    max_element = -1
    max_idx = -1
    for i in range(n): 
        if (nums[i] > max_element): 
            max_element = nums[i]
            max_idx = i
            ans += 1
        elif (nums[i] == max_element): 
            max_idx = i
            ans += 1

    print(ans)