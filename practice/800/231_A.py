l = int(input())
res = 0
for line in range(l): 
    arr = list(map(int, input().split()))
    if sum(arr) > 1: 
        res += 1
print(res)