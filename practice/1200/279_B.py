n, t = map(int, input().split())
books = list(map(int, input().split()))

res = 0 

# O(n) --> sliding window 
start = 0
end = 0 
total_time = 0
res = 0
for end in range(n): 
    total_time += books[end]
    while total_time > t: 
        total_time -= books[start]
        start += 1
    
    res = max(res, end - start + 1)

print(res)  

        