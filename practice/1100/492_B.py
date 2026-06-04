n, l = map(int, input().split())
poles = list(map(int, input().split()))

poles.sort() # O(n lg n) 

# Check extreme dists first 
d = 0.0 

d = float(max(d, poles[0] - 0, l - poles[-1]))
for i in range(n - 1): 
    d = max(d, float((poles[i + 1] - poles[i])/2))

print(d)